#!/bin/sh
choice=0
while [ $choice != "5" ]; do
echo "------------------------------------"  
echo "            MAIN MENU"
echo "------------------------------------"
echo -e "1. Ongoing processor Activity \n2. Users currently logged in \n3. Number of users currently logged in \n4. Users with bash shell \n5. Exit"
read choice
case $choice in
"1") top;;
"2") who -u;;
"3") echo " `who|wc -l`";;
"4") grep bash /etc/passwd|cut -d ":" -f 5|sort|uniq;;
"5") exit;; 
*) echo "Invalid selection input a numeric value from 1-5" ./utilities.sh;; 
esac

echo "Press [Enter] key to continue..."
read -s -n 1 continue
while [ $continue != "" ]; do
read -s -n 1 continue
done
clear


done