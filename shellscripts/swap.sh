read -p "enter the 1st number: " num1
read -p "enter the 2nd number: " num2

temp=$num1
num1=$num2
num2=$temp

echo "swapped numbers are $num1 and $num2"