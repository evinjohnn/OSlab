#!/bin/bash

echo "Enter a string:"
read string

echo "Please select an option:"
echo "1. Convert lowercase to UPPERCASE"
echo "2. Convert UPPERCASE to lowercase"
echo "3. Replace a substring"
echo "4. Find position of a substring"
read choice

case $choice in
    1)
        echo "$string" | tr 'a-z' 'A-Z'
        ;;
    2)
        echo "$string" | tr 'A-Z' 'a-z'
        ;;
    3)
        echo "Enter the substring to replace:"
        read old
        echo "Enter the replacement string:"
        read new
        echo "${string/$old/$new}"
        ;;
    4)
        echo "Enter the substring to find:"
        read sub
        pos=$(expr index "$string" "$sub")
        if [ $pos -eq 0 ]; then
            echo "Substring not found"
        else
            echo "Substring starts at position: $pos"
        fi
        ;;
    *)
        echo "Invalid option"
        ;;
esac
