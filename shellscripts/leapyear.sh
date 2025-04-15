echo -e "enter the year\n" 
read year

if (( $year%400 == 0 ));then
    echo "it is a leap year"
elif (( $year%100 == 0 ));then
    echo "it is not a leap year"
elif (( $year%4 == 0 ));then
    echo "it is a leap year"
else
    echo "not a leap year babygurl"
fi