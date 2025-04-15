read -p "enter the number: " num
n=$num
sum=0

while [ $num -gt 0 ];do
    sum=$(($sum + $num%10))
    num=$(($num/10))
done

echo "the sum of digits of $n is $sum"