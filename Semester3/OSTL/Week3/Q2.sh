echo "Enter n :"
read n
i=1
while test $i -le $n
do
no=`expr \( $i \% 2 \)`
if [ $no != 0 ]
then
echo $i
fi
i=`expr \( $i + 1 \)`
done
