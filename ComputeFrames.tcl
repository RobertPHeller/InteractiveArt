#!/usr/bin/tclsh
#*****************************************************************************
#
#  System        : 
#  Module        : 
#  Object Name   : $RCSfile$
#  Revision      : $Revision$
#  Date          : $Date$
#  Author        : $Author$
#  Created By    : Robert Heller
#  Created       : Mon Jul 11 09:43:48 2022
#  Last Modified : <220711.1025>
#
#  Description	
#
#  Notes
#
#  History
#	
#*****************************************************************************
#
#    Copyright (C) 2022  Robert Heller D/B/A Deepwoods Software
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

snit::type frame {
    typevariable MouldingLength 96
    typevariable MouldingWidth  1.0625
    typevariable Pieces -array {}
    option -width -type snit::double -default 36 -readonly yes
    option -height -type snit::double -default 24 -readonly yes
    constructor {args} {
        $self configurelist $args
        set l [expr {$options(-width)+(2*$MouldingWidth)}]
        set h [expr {$options(-height)+(2*$MouldingWidth)}]
        incr Pieces($l) 2
        incr Pieces($h) 2
    }
    typemethod CountUnits {} {
        set scraps [list]
        set totalcount 0
        foreach p [lsort -real [array names Pieces]] {
            set c $Pieces($p)
            puts [format {%2d pieces %8.4f long} $c $p]
            for {set i 0} {$i < $c} {incr i} {
                set havepiece no
                foreach s $scraps {
                    if {$s > $p} {
                        puts [format {Cut %8.4f from %8.4f scrap} $p $s]
                        set news [expr {$s - $p}]
                        set is [lsearch -exact $scraps $s]
                        set scraps [lreplace $scraps $is $is $news]
                        set havepiece yes
                        break
                    }
                }
                if {$havepiece} {continue}
                incr totalcount
                set remainder [expr {$MouldingLength - $p}]
                puts [format {Cut %8.4f from fresh 8' length} $p]
                lappend scraps $remainder
            }
        }
        puts [format {Need to get %d 8' lengths} $totalcount]
        puts [format {Will have %d scrap pieces:} [llength $scraps]]
        foreach s [lsort -real $scraps] {
            puts [format {%8.4f} $s]
        }
    }
}

frame HelloWorld -width 36 -height 24
frame GothemCity -width 36 -height 24
frame DrHoward   -width 29.5 -height 23.25
frame Chicken    -width 29 -height 21

frame CountUnits
