read -p "Enter the number: " num
temp=$num
sum=0

len=${#num}

while [ $num -gt 0 ]
do
    r=$(( num % 10 ))
    pow=1

    # Raise r to the power of len
    for (( i=0; i<len; i++ ))
    do
        pow=$(( pow * r ))
    done

    sum=$(( sum + pow ))
    num=$(( num / 10 ))
done

if [ $sum -eq $temp ]; then
    echo "$temp is an Armstrong number"
else
    echo "$temp is NOT an Armstrong number"
fi
