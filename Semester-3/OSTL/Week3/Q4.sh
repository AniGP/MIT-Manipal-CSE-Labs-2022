echo "Enter a no. :"
read n
p=1
i=1
while test $i -le $n
do
p=`expr \( $p \* $i \)`
i=$((i+1))
done
echo $p
