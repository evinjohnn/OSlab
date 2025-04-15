read -p "Enter the 1st number: " num1
read -p "Enter the 2nd number: " num2
read -p "Enter the 3rd number: " num3

if [ "$num1" -gt "$num2" ] && [ "$num1" -gt "$num3" ]; then
    echo "num1 is the greatest"
elif [ "$num3" -gt "$num2" ] && [ "$num3" -gt "$num1" ]; then
    echo "num3 is the greatest"
else
    echo "num2 is the greatest"
fi
