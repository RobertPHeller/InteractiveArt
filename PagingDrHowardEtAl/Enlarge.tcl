#*****************************************************************************
#
#  System        : 
#  Module        : 
#  Object Name   : $RCSfile$
#  Revision      : $Revision$
#  Date          : $Date$
#  Author        : $Author$
#  Created By    : Robert Heller
#  Created       : Wed Nov 7 11:02:15 2018
#  Last Modified : <181107.1137>
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


package require Tk
package require Img

set Stooges [image create photo -file {The-Three-Stooges-1930s-THE-THREE-STOOGES-1930s-Original-Prop-MALLET-Hammer-3-3.jpg}]

set width [image width $Stooges];# pixels
set height [image height $Stooges];# pixels
set aspect [expr {double($width) / double($height)}]
puts stderr "*** $width x $height -- $aspect"
set totalheight 24;# inches
set totalwidth [expr {int(ceil($totalheight * $aspect))}]
puts stderr "*** $totalwidth x $totalheight"

set xsheets [expr {int(ceil($totalwidth / 10.5))}]
set ysheets [expr {int(ceil($totalheight / 8.0))}]

puts stderr "*** $xsheets x $ysheets"

set pageheight 8i
set pagewidth 10.5i

set impageheight [expr {int(ceil(double($height)/double($ysheets)))}]
set impagewidth [expr {int(ceil(double($width)/double($xsheets)))}]

pack [canvas .c -width $width -height $height]

.c create image 0 0 -image $Stooges -anchor nw
update idle
set pageno 0

for {set py 0} {$py < $totalheight} {incr py 8} {
    set yoff [expr {int(ceil((double($py)/double($totalheight))*$height))}]
    for {set px 0} {$px < $totalwidth} {set px [expr {$px + 10.5}]} {
        set xoff [expr {int(ceil((double($px)/double($totalwidth))*$width))}]
        incr pageno
        .c postscript -file PagingDrHowardEtAl-Page$pageno.ps \
              -height $impageheight \
              -width  $impagewidth \
              -x      $xoff \
              -y      $yoff \
              -pageanchor nw \
              -pageheight $pageheight \
              -pagewidth $pagewidth \
              -pagex .25i -pagey .25i \
              -rotate true
    }
}
exit
