while true; do
    echo -e "\nEnter the numbers one by one:"
    read num1
    read num2

    echo -e "Choose an operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division"
    read ch

    case $ch in
        1)
            result=$((num1 + num2))
            echo "The sum of the two numbers is: $result"
            ;;
        2)
            result=$((num1 - num2))
            echo "The difference of the two numbers is: $result"
            ;;
        3)
            result=$((num1 * num2))
            echo "The product of the two numbers is: $result"
            ;;
        4)
            if [ "$num2" -ne 0 ]; then
                result=$((num1 / num2))
                echo "The quotient of the two numbers is: $result"
            else
                echo "Error: Division by zero is not allowed."
            fi
            ;;
        *)
            echo "Invalid choice."
            ;;
    esac

    echo -e "\nDo you want to continue? (y/n)"
    read choice
    if [[ "$choice" != "y" && "$choice" != "Y" ]]; then
        echo "Goodbye!"
        break
    fi
done
