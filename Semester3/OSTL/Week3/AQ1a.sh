#!/bin/bash
echo "Enter a string :"
read str
n=`expr length $str`
i=1
palindrome=true
while [ $i -le `expr $n \/ 2` ]
do
if [ `expr substr $str $i 1` != `expr substr $str $(($n+1-$i)) 1` ]
then
palindrome=false
fi
i=$((i+1))
done
if $palindrome
then
echo "yes"
else
echo "no"
fi
