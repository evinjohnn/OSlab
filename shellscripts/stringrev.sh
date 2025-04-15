read -p "enter the string" string
reversed=""

len=${#string}

for ((i=len-1;i>=0;i--));do
reversed="$reversed${string:$i:1}"
done

echo -e "\nreversed string is $reversed"