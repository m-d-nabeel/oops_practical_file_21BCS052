# Command to run the program

```bash
g++ tinypng_thing.cpp -o tinypng_thing.o -L ./tinypng-master/ -ltinypng -lpng
./tinypng_thing.o | tee -a output.txt
```
