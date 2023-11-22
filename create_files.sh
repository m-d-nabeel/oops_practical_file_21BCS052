#!/bin/bash

# Replace 'ROLL_NO' with your actual roll number
ROLL_NO="21BCS052"

# Loop from 1 to 16 and create files in the specified format
for ((i=1; i<=16; i++)); do
    dirname="oops_${ROLL_NO}_LA${i}_report"
    mkdir "$dirname"
    touch "$dirname/oops_${ROLL_NO}_LA${i}_report.docx"
    echo "Created $dirname"
done
