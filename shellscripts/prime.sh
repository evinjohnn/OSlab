read -p "enter the num to be checked : " num

if [ $num -lt 2 ]; then
 echo "number is not prime"
 exit
fi
for ((i=2; i<num/2; i++)); 
do
    if (($num%i==0));then
    echo "number is not prime"
    exit
    fi
done

echo "number is prime"