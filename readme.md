# EE361C Term Project: CPU Parallel Sorting Implementations
## Suhas Raja, Matthew Jones, Matthew Golla, Alan Penichet

## Instructions

1. call "make" in the command line
2. to run: ./termProject <filename.txt>  {type of sort}
3. output files will be in "outputs"

### Example

./termProject inputs/test_50000.txt radix

The output file will be called "out_radix_50000.txt"

### Reminders
- The type of sort should be in this set: {brick, radix, merge, quick, bitonic}
- The number of threads is defined in common.h
- In the input file follow the format: 1, 2, 3, 5, ... , n
- For the input file, make sure to include the path to the file if it is in a folder
- There is a Python script that can be used to generate input files

## Graphs

Note: Each plotted time is the average of 5 executions.

![Performance on increasingly sized datasets](/graphs/8threadsorting.png)

![Performance on increasingly sized datasets](/graphs/bricksorting.png)

As the size of the dataset doubles, our runtime approximately doubles for each algorithm while running 8 threads, indicating a near linear time complexity.


![Performance as threads increase](/graphs/sort150.png)

![Performance as threads increase](/graphs/bricksort150.png)

As the number of threads increases, the runtime for sorting decreases.
