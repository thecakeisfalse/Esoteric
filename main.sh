#!   bin/bash

#VERSION=1.0.2

echo -e "             ____   "
echo -e "Entynet     /\___\  "
echo -e "Project    /\ \___\ "
echo -e "Search     \ \/ / / "
echo -e "(Demo)      \/_/_/  by cake"

pre = 'https://'
read -p "Enter URL: " post
if [["$post == ""]]
then
	start 'https://github.com/entynetproject/ehtools'
else
	line = '$pre + $post'
	start $line
sleep 25
