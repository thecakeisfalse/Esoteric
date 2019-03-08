#! /bin/bash

# 
#            --------------------------------------------------
#                            The Cake Is A Lie          
#            --------------------------------------------------
#
#        Copyright (Shell) <2019>  <thecakeisfalse (Me)>
#
#        I don't know what do I need to write where. And because of it, I copy
#        text from EntyNet's EHTools. I am strange cake.
#
#        This program is free software: you can redistribute it and/or modify
#        it under the terms of the GNU General Public License as published by
#        the Free Software Foundation, either version 3 of the License, or
#        any later version.
#
#        This program is distributed in the hope that it will be useful,
#        but WITHOUT ANY WARRANTY; without even the implied warranty of
#        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#        GNU General Public License for more details.
#
#        You should have received a copy of the GNU General Public License
#        along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#	 VERSION=2.0.1
#

clear

echo -e "             ____   "
echo -e "Entynet     /\___\  "
echo -e "Project    /\ \___\ "
echo -e "Search     \ \/ / / "
echo -e "Module      \/_/_/  by cake"

sleep 11

clear 
read -p "Enter your link (without https://): " line

if [ "$line" == "" ]
then
    echo "Output: basic"
    start "https://github.com/entynetproject/ehtools"
else
    echo "Output: "${line}" - true"
    search='https://'${line}
    start $search
fi

sleep 5
