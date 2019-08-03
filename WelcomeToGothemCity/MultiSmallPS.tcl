#*****************************************************************************
#
#  System        : 
#  Module        : 
#  Object Name   : $RCSfile$
#  Revision      : $Revision$
#  Date          : $Date$
#  Author        : $Author$
#  Created By    : Robert Heller
#  Created       : Sat Aug 3 10:50:36 2019
#  Last Modified : <190803.1314>
#
#  Description	
#
#  Notes
#
#  History
#	
#*****************************************************************************
#
#    Copyright (C) 2019  Robert Heller D/B/A Deepwoods Software
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

snit::type MultiSmallPS {
    typevariable _psfiles {batman.ps  catwoman.ps  joker1.ps  madhatter.ps  
        riddler2.ps  riddler.ps tiny-umbrella.ps poison-ivy.ps rifle.ps}
    typevariable _PSHeadFmt "%%!PS-Adobe-2.0\n%%%%Title: %s\n%%%%Creator: %s\n%%%%CreationDate: %s\n%%%%BoundingBox: 0 0 612 792\n%%%%EndComments\n"
    typemethod _DoOnePSFile {fp file x y} {
        catch {array unset bbox}
        array set bbox {llx 0 lly 0 urx 0 ury 0}
        if {![catch {open $file r} psfp]} {
            while {[gets $psfp  line] >= 0} {
                regexp -nocase {^%%BoundingBox[:]?[[:space:]]*([[:digit:]+-.])[[:space:]]*([[:digit:]+-.]*)[[:space:]]*([[:digit:]+-.]*)[[:space:]]*([[:digit:]+-.]*)$} \
                      "$line" -> bbox(llx) bbox(lly) bbox(urx) bbox(ury)
                if {[regexp -nocase {^%%EndComments$} $line] > 0} {break}
            }
            puts $fp {userdict begin save gsave /showpage {} def /erasepage {} def /copypage {} def}
            puts $fp [format {%6.3f %6.3f translate} $x $y]
            while {[gets $psfp line] >= 0} {
                if {[regexp -nocase {^%%} $line] > 0} {continue}
                puts $fp "$line"
            }
            close $psfp
            puts $fp {grestore restore end}
        }
    }
    typemethod main {args} {
        global argv0
        set outfile [from args -outfile "villians.ps"]
        set fp [open $outfile w]
        puts $fp [format $_PSHeadFmt $outfile $argv0 [clock format [clock seconds]]]
        set x [expr {.5*72}]
        set y [expr {.5*72}]
        foreach p $_psfiles {
            $type _DoOnePSFile $fp $p $x $y
            set x [expr {$x + 72}]
            if {$x > (7*72)} {
                set x [expr {.5*72}]
                set y [expr {$y + 72}]
            }
        }
        puts $fp {showpage}
        puts $fp {%%EOF}
    }
}

MultiSmallPS main $::argv


