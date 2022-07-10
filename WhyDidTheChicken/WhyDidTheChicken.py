#!/usr/local/bin/FreeCAD019
#*****************************************************************************
#
#  System        : 
#  Module        : 
#  Object Name   : $RCSfile$
#  Revision      : $Revision$
#  Date          : $Date$
#  Author        : $Author$
#  Created By    : Robert Heller
#  Created       : Sun Jul 10 14:27:21 2022
#  Last Modified : <220710.1631>
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


import FreeCAD as App
import Part
from FreeCAD import Base
import Mesh
import os
import sys
sys.path.append(os.path.dirname(__file__))

import datetime

class PedSignalFrame(object):
    _innerWidth = 1.26*25.4
    _innerHeight = 1.26*25.4
    _outerWidth = 1.52*25.4
    _outerHeight = 1.52*25.4
    _thinkness   = .13*25.4
    def __init__(self,name,origin):
        self.name = name
        if not isinstance(origin,Base.Vector):
            raise RuntimeError("origin is not a Vector")
        self.origin = origin
        ox = origin.x
        oy = origin.y
        oz = origin.z
        ZNorm=Base.Vector(0,0,1)
        ZThick=Base.Vector(0,0,self._thinkness)
        panel = Part.makePlane(self._outerWidth,self._outerHeight,origin,\
                                ZNorm).extrude(ZThick)
        self.frame = panel.cut(\
           Part.makePlane(self._innerWidth,self._innerHeight,\
             origin.add(Base.Vector((self._outerWidth-self._innerWidth)/2,\
                                    (self._outerHeight-self._innerHeight)/2.0,\
                                    0)),ZNorm).extrude(ZThick))
    def show(self):
        doc = App.activeDocument()
        obj = doc.addObject("Part::Feature",self.name)
        obj.Shape = self.frame
        obj.Label=self.name
        obj.ViewObject.ShapeColor=tuple([0.0,0.0,0.0])
        self.obj = obj
    def makeStl(self,filename):
        objs=[]
        objs.append(self.obj)
        Mesh.export(objs,filename)
        

class TrafficLightFrame(object):
    _lampdiameter = 10
    _lampspacing  = 5*2.54
    _height       = ((6*2.54)*3)-(2*2.54)
    _width        = 6*2.54
    _thinkness    = .13*25.4
    _shieldThick  = 1
    _shieldLength = 12
    def __init__(self,name,origin):
        self.name = name
        if not isinstance(origin,Base.Vector):
            raise RuntimeError("origin is not a Vector")
        self.origin = origin
        ox = origin.x
        oy = origin.y
        oz = origin.z
        ZNorm=Base.Vector(0,0,1)
        ZThick=Base.Vector(0,0,self._thinkness)
        panel = Part.makePlane(self._width,self._height,origin,\
                                ZNorm).extrude(ZThick)
        centerX = self._width/2.0
        yellowY = self._height/2.0
        redY    = yellowY+self._lampspacing
        greenY  = yellowY-self._lampspacing
        panel = panel.cut(Part.Face(Part.Wire(Part.makeCircle(\
                                               self._lampdiameter/2,\
                                               origin.add(Base.Vector(centerX,\
                                               redY,0))))).extrude(ZThick))
        panel = panel.cut(Part.Face(Part.Wire(Part.makeCircle(\
                                               self._lampdiameter/2,\
                                               origin.add(Base.Vector(centerX,\
                                               yellowY,0))))).extrude(ZThick))
        panel = panel.cut(Part.Face(Part.Wire(Part.makeCircle(\
                                               self._lampdiameter/2,\
                                               origin.add(Base.Vector(centerX,\
                                               greenY,0))))).extrude(ZThick))
        panel = panel.fuse(self._shieldAt(centerX,redY))
        panel = panel.fuse(self._shieldAt(centerX,yellowY))
        panel = panel.fuse(self._shieldAt(centerX,greenY))
        self.frame = panel
    def show(self):
        doc = App.activeDocument()
        obj = doc.addObject("Part::Feature",self.name)
        obj.Shape = self.frame
        obj.Label=self.name
        obj.ViewObject.ShapeColor=tuple([0.0,0.0,0.0])
        self.obj = obj
    def makeStl(self,filename):
        objs=[]
        objs.append(self.obj)
        Mesh.export(objs,filename)
    def _shieldAt(self,centerX,centerY):
        shieldCenter = self.origin.add(Base.Vector(centerX,\
                                                   centerY,\
                                                   self._thinkness))
        shieldExtrude = Base.Vector(0,0,self._shieldLength)
        shield = Part.Face(Part.Wire(\
                Part.makeCircle((self._lampdiameter/2)+self._shieldThick,\
                                shieldCenter)))\
               .extrude(shieldExtrude)
        shield = shield.cut(Part.Face(Part.Wire(\
                Part.makeCircle(self._lampdiameter/2,shieldCenter)))\
                .extrude(shieldExtrude))
        return(shield)

if __name__ == '__main__':
    App.ActiveDocument=App.newDocument("3D prints")
    doc = App.activeDocument()
    op = Base.Vector(0,0,0)
    #pedsignalframe = PedSignalFrame("pedframe",op)
    #pedsignalframe.show()
    #pedsignalframe.makeStl("pedsignalframe.stl")
    trafficlightframe = TrafficLightFrame("trafficlight",op)
    trafficlightframe.show()
    trafficlightframe.makeStl("trafficlightframe.stl")
    Gui.SendMsgToActiveView("ViewFit")
    Gui.activeDocument().activeView().viewIsometric()

