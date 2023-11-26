#!/bin/bash
# ROLL_NO="21BCS052"
# YOUR_ROLL_NO="21BCS085"
# for ((i=1; i<=10; i++)); do
#     dirname="oops_${ROLL_NO}_LA${i}_report"
#     new_dir_name="oops_${YOUR_ROLL_NO}_LA${i}_report"
#     mv "$dirname" "$new_dir_name"
#     mv "$new_dir_name/oops_${ROLL_NO}_LA${i}_report.docx" "$new_dir_name/oops_${YOUR_ROLL_NO}_LA${i}_report.docx"
#     echo "Renamed $dirname to $new_dir_name"
# done
# g++ default_constructor.cpp && ./a.out | tee -a output.txt

#!/bin/bash

for dirname in */; do
    new_dirname="${dirname//_report/}"
    mv "$dirname" "$new_dirname"
    echo "Renamed $dirname to $new_dirname"
done
