#*****************************************************************************
#
#  System        : 
#  Module        : 
#  Object Name   : $RCSfile$
#  Revision      : $Revision$
#  Date          : $Date$
#  Author        : $Author$
#  Created By    : Robert Heller
#  Created       : Tue Nov 6 13:24:15 2018
#  Last Modified : <181106.1701>
#
#  Description	
#
#  Notes
#
#  History
#	
#*****************************************************************************
#
#    Copyright (C) 2018  Robert Heller D/B/A Deepwoods Software
#			51 Locke Hill Road
#			Wendell, MA 01379-9728
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
# 
#
#*****************************************************************************

package require snit
package require pdf4tcl


snit::integer uint -min 0
snit::integer uintnz -min 1

snit::type Window {
    option -xpos -default 0 -type snit::double -readonly true
    option -ypos -default 0 -type snit::double -readonly true
    option -lit  -default false -type snit::boolean -readonly true
    constructor {args} {
        $self configurelist $args
    }
    method draw {pdf bxoff pageX pageY pageW pageH} {
        #puts stderr "*** $self draw $pdf $bxoff $pageX $pageY $pageW $pageH"
        set wxorg [expr {$bxoff + [$self cget -xpos]}]
        set wyorg [$self cget -ypos]
        #puts stderr "*** $self draw: $wxorg $wyorg"
        if {$wxorg > ($pageX + $pageW)} {return}
        if {($wxorg + .25) < $pageX} {return}
        if {$wyorg > ($pageY + $pageH)} {return}
        if {($wyorg + .25) < $pageY} {return}
        set wx [expr {$wxorg - $pageX}]
        set ww .25
        set wx1 [expr {$wx + $ww}]
        if {$wx < 0} {
            set ww $wx1
            set wx 0
        }
        if {($ww + $wx) > $pageW} {
            set ww [expr {$pageW - $wx}]
        }
        set wy [expr {$wyorg - $pageY}]
        set wh .25
        set wy1 [expr {$wy + $wh}]
        if {$wy < 0} {
            set wh $wy1
            set wy 0
        }
        if {($wh + $wy) > $pageH} {
            set wh [expr {$pageH - $wy}]
        }
        $pdf setStrokeColor .15 .15 .15
        if {[$self cget -lit]} {
            $pdf setFillColor 1 1 1
        } else {
            $pdf setFillColor 0 0 0
        }
        $pdf rectangle $wx $wy $ww $wh -filled 1 -stroke 1
    }
}


snit::type Building {
    option -xpos  -default 0 -type uint -readonly true
    option -width -default 1 -type uintnz -readonly true
    option -height -default 1 -type uintnz -readonly true
    variable windows [list]
    constructor {args} {
        $self configurelist $args
        $self generateWindows
    }
    method generateWindows {} {
        set wy .25
        while {($wy + .25) < [$self cget -height]} {
            set wx .25
            while {($wx + .25) < [$self cget -width]} {
                lappend windows [Window create %AUTO% -xpos $wx -ypos $wy \
                                     -lit [expr {rand() > .95}]]
                set wx [expr {$wx + .25}]
            }
            set wy [expr {$wy + .25}]
        }
    }
    method draw {pdf pageX pageY pageW pageH} {
        #puts stderr "*** $self draw $pdf $pageX $pageY $pageW $pageH"
        set x [$self cget -xpos]
        set w [$self cget -width]
        set h [$self cget -height]
        #puts stderr "*** $self draw: $x $w $h"
        if {$x > ($pageX + $pageW)} {return}
        if {($x + $w) < $pageX} {return}
        #puts stderr "*** $self draw: in X"
        #puts stderr "*** $self draw: $h $pageY"
        if {$h <= $pageY} {return}
        #puts stderr "*** $self draw: in Y"
        set bx [expr {$x - $pageX}]
        #puts stderr "*** $self draw: $x $pageX $bx"
        set bw $w
        set bx1 [expr {$bx + $bw}]
        #puts stderr "*** $self draw: $bw $bx1"
        if {$bx < 0} {
            set bw $bx1
            set bx 0
        }
        if {($bw + $bx) > $pageW} {
            set bw [expr {$pageW - $bx}]
        }
        set by 0
        set bh [expr {$h - $pageY}]
        if {$bh > $pageH} {set bh $pageH}
        $pdf setFillColor 0 0 0
        #puts stderr "*** $self draw: $bx $by $bw $bh"
        $pdf rectangle $bx $by $bw $bh -filled 1
        foreach w $windows {
            #puts stderr "*** $self draw: w = $w"
            $w draw $pdf $x $pageX $pageY $pageW $pageH
        }
    }
}

                
                                     

snit::type CityScape {
    typevariable totalWidth 36;#         inches
    typevariable maxBuildingHeight 16;#  inches
    typevariable maxBuildingWidth 6;#    inches
    typevariable paperType letter
    
    variable buildingList [list]
    component pdf
    delegate option -outputfile to pdf as -file
    constructor {args} {
        #puts stderr "*** $type create $self $args"
        set pdf [::pdf4tcl::new %AUTO% -file [from args -outputfile] \
                 -paper $paperType -unit i -margin .25i \
                 -landscape true -orient false]
        #puts stderr "*** $type create $self $args: pdf = $pdf"
        $self configurelist $args
    }
    method generateBuildings {{seed 0}} {
        #puts stderr "*** $self generateBuildings $seed"
        expr {srand($seed)}
        set buildingX 0
        while {($buildingX+$maxBuildingWidth) < $totalWidth} {
            #puts stderr "*** $self generateBuildings: buildingX = $buildingX"
            set buildingHeight [expr {1+int(rand()*($maxBuildingHeight-1))}]
            set buildingWidth  [expr {1+int(rand()*($maxBuildingWidth-1))}]
            lappend buildingList [Building create %AUTO% \
                                  -xpos $buildingX \
                                  -width $buildingWidth \
                                  -height $buildingHeight]
            incr buildingX $buildingWidth
        }
        if {$buildingX < $totalWidth} {
            set buildingWidth [expr {$totalWidth - $buildingX}]
            set buildingHeight [expr {1+int(rand()*($maxBuildingHeight-1))}]
            lappend buildingList [Building create %AUTO% \
                                  -xpos $buildingX \
                                  -width $buildingWidth \
                                  -height $buildingHeight]
        }
    }
    method drawBuildings {} {
        for {set pageY 0} {$pageY < $maxBuildingHeight} {incr pageY 8} {
            for {set pageX 0} {$pageX < $totalWidth} {set pageX [expr {$pageX + 10.5}]} {
                $pdf startPage
                foreach b $buildingList {
                    #puts stderr "*** $self drawBuildings: b = $b"
                    $b draw $pdf $pageX $pageY 10.5 8.0
                }
            }
        }
        $pdf destroy
    }
}

set object [CityScape create %AUTO% -outputfile test.pdf]
$object generateBuildings [clock scan now]
$object drawBuildings

