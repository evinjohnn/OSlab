read -p "Enter the number to be identified: " num
echo "Input number: $num"

if (( num % 2 == 0 )); then
  echo "The number is even"
else
  echo "The number is odd"
fi