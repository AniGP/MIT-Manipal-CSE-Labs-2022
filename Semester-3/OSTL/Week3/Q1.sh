echo "Entera no. :"
read n
no=`expr \( $n \% 2 \)`
if [ $no -eq 0 ]
then
echo "Even"
else
echo "Odd"
fi
