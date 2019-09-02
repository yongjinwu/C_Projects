#!/bin/sh
if [ $# -eq 0 ]; then
echo -e "Error:no target specified\nUsage:./myrm <files>"
else
mkdir -p /tmp/yongjwu/eecs2031m/a1/recycle-bin 
for i in "$@"
do
cp $i /tmp/yongjwu/eecs2031m/a1/recycle-bin
echo "deleting $i"
rm $i
done 
fi
