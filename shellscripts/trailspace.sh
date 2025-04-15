
read -p "Enter the string: " string
echo -e "\nEnter the option: \n1. Remove leading white space \n2. Remove trailing white space"
read ch

case $ch in
    1)
        # Remove leading whitespace
        trimmed="${string#"${string%%[![:space:]]*}"}"
        echo "After removing leading whitespace: '$trimmed'"
        ;;
    2)
        # Remove trailing whitespace
        trimmed="${string%"${string##*[![:space:]]}"}"
        echo "After removing trailing whitespace: '$trimmed'"
        ;;
    *)
        echo "Invalid option"
        ;;
esac
