// -!- c++ -!- //////////////////////////////////////////////////////////////
//
//  System        : 
//  Module        : 
//  Object Name   : $RCSfile$
//  Revision      : $Revision$
//  Date          : $Date$
//  Author        : $Author$
//  Created By    : Robert Heller
//  Created       : Fri Aug 19 09:29:25 2022
//  Last Modified : <220819.1342>
//
//  Description	
//
//  Notes
//
//  History
//	
/////////////////////////////////////////////////////////////////////////////
//
//    Copyright (C) 2022  Robert Heller D/B/A Deepwoods Software
//			51 Locke Hill Road
//			Wendell, MA 01379-9728
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
// 
//
//////////////////////////////////////////////////////////////////////////////

#ifndef __DIRECTORYLIST_H
#define __DIRECTORYLIST_H

#include <SD.h>
#include <vector>
#include <string>
#include <Print.h>
#include <string.h>

typedef std::vector<std::string> StringVector;

class DirectoryList {
public:
    DirectoryList(File root) 
    {
        while(true) {
            File entry = root.openNextFile();
            if (! entry) break;
            if (fileIsLife_(entry))
            {
                fileList_.push_back(std::string(entry.name()));
            }
            entry.close();
        }
        root.close();
    }
    size_t  numberOfFiles() const {return fileList_.size();}
    void showFiles(Print &output,size_t first,size_t count,size_t index)
    {
        size_t i;
        for (i = 0; i < count; i++)
        {
            if ((i+first) >= fileList_.size())
            {
                break;
            }
            if ((i+first) == index)
            {
                output.print(">>");
            }
            else
            {
                output.print("  ");
            }
            output.println((fileList_[i+first].c_str()));
        }
    }
    const char * operator[](int i) const
    {
        return fileList_[i].c_str();
    }
private:
    StringVector fileList_;
    boolean fileIsLife_(File entry) const
    {
        if (entry.size() == 0) return false;
        char *dot = strrchr(entry.name(),'.');
        if (dot == NULL) return false;
        if (strncmp(".life",dot,5) != 0) return false;
        return true;
    }
};

        
#endif // __DIRECTORYLIST_H

