#!/bin/bash
ROLL_NO="21BCS052"
for ((i=1; i<=16; i++)); do
    dirname="oops_${ROLL_NO}_LA${i}_report"
    mkdir "$dirname"
    touch "$dirname/oops_${ROLL_NO}_LA${i}_report.docx"
    echo "Created $dirname"
done
# g++ default_constructor.cpp && ./a.out | tee -a output.txt