read -p "enter circle radius:" rad

area=$(echo "scale=2; 3.14159*$rad*$rad" | bc)

echo "the area of the circle is $area  square units"