# EE361C Term Project: CPU Parallel Sorting Implementations
Suhas Raja, Matthew Jones, Matthew Golla, Alan Penichet

## Instructions

1. call "make" in the command line to compile
2. to run: ./termProject <filename.txt>  {type of sort}
3. output files will be in "outputs"

### Example

./termProject inputs/test_50000.txt radix

The output file will be called "out_radix_50000.txt" in this case

### Reminders
- The type of sort should be in this set: {brick, radix, merge, quick, bitonic}
- The number of threads is defined in common.h, set number of threads to 1 for the sequential version
- In the input file follow the format: 1, 2, 3, 5, ... , n
- For the input file, make sure to include the path to the file if it is in a folder
- There is a Python script that can be used to generate input files

## Algorithms
For our term project we implemented parallelized versions of brick, bitonic, merge, radix, and quick sorting algorithims in C++ using OpenMP. To accomplish this, we first developed a sequential version of each algorithm, then added the appropriate OpenMP commands to parallelize the algorithms. Below is a brief description of each algorithm. 

### Brick Sort
Brick sort is a basic sorting algorithm that compares adjacent pairs of elements, with alternating offsets. With each pair of elements being designated a process per each iteration, the alternating nature of the pair offset allows for larger elements to drift towards the right, and smaller elements towards the left. Since each element moves at most 1 index each iteration, brick sort takes up to O(n^2) time sequentially. While using n threads, brick sort should approach O(n) time complexity. 

### Bitonic Sort
Bitonic sort operates by breaking the array into a series of bitonic sequences (those which are increasing, then decreasing), and merging bitonic sequences in parallel. The time complexity for sequential bitonic sort is O(n * log^2 n). When using n threads, bitonic sort should approach O(log^2 n) time complexity. 

### Merge Sort
Merge sort is a divide and conquer sorting algorithm. It divides a given array into many subsequences and merges them together in ascending order. When implemented sequentially merge sort has O(n * log n) time complexity, but with n threads in parallel has O(log n) time complexity. 

### Radix Sort
Radix sort iterates from the least significant bit to the most significant bit, and at each iteration, sorts elements based only on the corresponding bit. By preserving the order from previous iterations when the current iteration is processed, the resulting array maintains the work of prior iterations and becomes increasingly sorted. Radix sorts complexity is dependent both on the number of bits it must consider as well as the number of elements. Radix sort has O(d * (n + b)) where n is the number of elements, d is the number of possible digits to consider, and b is the base representation for the elements. When implemented in parallel, the time complexity is 
O(d * (log n + b)). 

### Quick Sort
Quick sort is a divide and conquer algorithm that uses pivots. A pivot is just an element in the array that is being sorted. Quick sort recursively ensures that all the elements to the right of the pivot are larger than the pivot, and all elements to the left of the pivot are smaller than the pivot. When imlemented sequentially, quick sort has O(n * log n) time complexity. 

## Graphs

Note: Each plotted time is the average of 5 executions of the code on the ECE Kamek Virtual Machine. Also, Brick sort is graphed separately as it takes significantly more time than the other sorts. 

### Performance as Dataset Size Increases for Bitonic, Merge, Quick, and Radix Sorts (8 threads)
![Performance on increasingly sized datasets](/graphs/8threadsorting.png)

#### Key
Red: Bitonic, Green: Merge, Orange: Quick, Black: Radix

### Performance as Dataset Size Increases for Brick Sort (8 threads)
![Performance on increasingly sized datasets](/graphs/bricksorting.png)

#### Key
Purple: Brick

As the size of the dataset doubles, our runtime approximately doubles for Bitonic, Merge, Quick, Radix while running 8 threads, indicating a near linear time complexity. For brick sort, the line appears to be nonlinear, indicating a nonlinear time complexity.

### Performance as Number of Threads Increases for Bitonic, Merge, Quick, and Radix Sorts (150,000 elements)
![Performance as threads increase](/graphs/sort150.png)

#### Key
Red: Bitonic, Green: Merge, Orange: Quick, Black: Radix

### Performance as Number of Threads Increases for Brick Sort (150,000 elements)
![Performance as threads increase](/graphs/bricksort150.png)

#### Key
Purple: Brick

As the number of threads increases, the runtime for sorting decreases, but with diminishing returns.
