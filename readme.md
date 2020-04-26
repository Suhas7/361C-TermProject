# EE361C Term Project: CPU Parallel Sorting Implementations
## Suhas Raja, Matthew Jones, Matthew Golla, Alan Penichet

# Instructions

1. call "make" in the command line
2. to run: ./termProject <filename.txt>  <type of sort>

The type of sort should be in this set: {brick, radix, merge, quick, bitonic}
The number of threads is defined in common.h

Note: in the input file follow the format: 1, 2, 3, 5, ... 

![Performance on increasingly sized datasets](/8threadsorting.png)

![Performance on increasingly sized datasets](/bricksorting.png)

As the size of the dataset doubles, our runtime approximately doubles for each algorithm while running 8 threads, indicating a near linear time complexity.


![Performance as threads increase](/sort150.png)

![Performance as threads increase](/bricksort150.png)

As the number of threads increases, the runtime for sorting decreases.
