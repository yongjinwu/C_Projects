#!/bin/sh
echo -e "Welcome to the number game.\nGuess a number between 1 and 64 (inclusive)."
Num=$(( ($RANDOM % 64) + 1 ))

attempts=0

while [ $attempts -lt 6 ]; do
read guess
if [ $guess -lt $Num ]; 
then
echo -e "Too small."

elif [ $guess -gt $Num ]; 
then
echo -e "Too big."

else
echo "You won!"
exit
fi

if [ $attempts -eq 5 ];
then 
echo "You lost!"
exit
fi

echo "Try again."
attempts=$(( $attempts + 1 ))
done











