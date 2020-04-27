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

## Algorithms

### Brick Sort
Brick sort is a basic parallel sorting algorithm that compares adjacent pairs of elements, with alternating offset. With each pair of elements being designated a process per each iteration, the alternating nature of the pair offset allows for larger elements to drift towards the right, and smaller elements towards the left. Since each element moves at most 1 index each iteration, brick sort takes up to O(n^2) time despite being parallel.

### Bitonic Sort
Bitonic sort operates by breaking the array into a series of bitonic sequences (those which are increasing, then decreasing), and merging bitonic sequences in parallel.


### Merge Sort
Merge sort is a recursive parallel sorting algorithm. It divides a given array into many subsequences (of initial length 1) and applies the parallel merge algorithm to combine them together while maintaining the ascending sortedness of the combined arrays. [insert complexity]

### Radix Sort
Radix sort iterates from the least significant bit to the most significant bit, and at each iteration, sorts elements based only on the corresponding bit. By preserving the order from previous iterations when the current iteration is processed, the resulting array maintains the work of prior iterations and becomes increasingly sorted. Radix sorts complexity is dependent both on the number of bits it must consider as well as the number of elements, with O(bn) time.


### Quick Sort

## Graphs

Note: Each plotted time is the average of 5 executions.

![Performance on increasingly sized datasets](/graphs/8threadsorting.png)

![Performance on increasingly sized datasets](/graphs/bricksorting.png)

As the size of the dataset doubles, our runtime approximately doubles for each algorithm while running 8 threads, indicating a near linear time complexity.


![Performance as threads increase](/graphs/sort150.png)

![Performance as threads increase](/graphs/bricksort150.png)

As the number of threads increases, the runtime for sorting decreases.
