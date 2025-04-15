read -p "Enter the number: " num
fact=1

if [ "$num" -lt 0 ]; then
    echo "Factorial is not possible for negative numbers."
    exit 1
fi

for (( i=2; i<=num; i++ ))
do
    fact=$(( fact * i ))
done

echo "The factorial of $num is $fact"
