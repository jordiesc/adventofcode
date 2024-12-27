
#!/bin/bash

suma=0
match=$(grep -oP 'mul\(\K[0-9]+,[0-9]+(?=\))' input.txt)

for pair in $match; do
    num1=$(echo $pair | cut -d',' -f1)
    num2=$(echo $pair | cut -d',' -f2)
    echo "num1=$num1, num2=$num2"
    suma=$(((num1 * num2) + suma))
done

echo "suma=$suma"
