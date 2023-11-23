# Command to run the program

```bash
g++ main.cpp -o main.o -L ./tinypng-master/ -ltinypng -lpng
./main.o | tee -a output.txt
```
