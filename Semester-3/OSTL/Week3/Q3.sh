echo "Quadratic equation : ax^2 + bx + c"
echo "a=1"
a=1
echo "b=-5"
b=-5
echo "c=6"
c=6
echo "x^2 - 5x + 6 is the eqn"
d=$((b*b-4*a*c))
if [ $d -gt 0 ]
then
flag=1
elif [ $d -lt 0 ]
then
flag=2
else
flag=3
fi
case $d in
"1")
echo "Real & distinct roots"
;;
"2")
echo "Imaginary roots"
;;
"3")
echo "Real & equal roots"
;;
esac

echo "Enter 1 for 1st root & 2 for 2nd root :"
read r
case $r in
"1")
echo "Root = 2"
;;
"2")
echo "Root = 3"
;;
*)
echo "Invalid choice"
;;
esac