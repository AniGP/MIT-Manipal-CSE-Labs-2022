echo "Enter no. of nos. :"
read n
i=1
sum=0
while [ $i -le $n ]
do
read x
sum=`expr $sum + $x`
i=$((i+1))
done
echo $sum
