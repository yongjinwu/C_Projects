#!/bin/sh
num="Usage -./calculator.sh value1 operator value2\nWhere,\nvalue1: numeric value\nvalue2: numeric value\noperator: one of +,-,/,x"
if [ $# -eq 0 ]; then
echo -e $num
exit
elif [ "$2" == "/" ] && [ "$3" -eq 0 ]; then
echo "Division-by-zero Error!"
exit
elif [ "$2" == "+" ]; then
num=$(( $1 + $3 ))

elif [ "$2" == "-" ]; then
num=$(( $1 - $3 ))

elif [ "$2" == "/" ]; then
num=$(( $1 / $3 ))

elif [ "$2" == "x" ]; then
num=$(( $1 * $3 ))

fi

echo -e $num 