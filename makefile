termProject: main.o bitonic.o brick.o merge.o quick.o radix.o 
	g++ -o termProject main.o bitonic.o brick.o merge.o quick.o radix.o -fopenmp
main.o: main.cpp common.h
	g++ -c -fopenmp main.cpp
bitonic.o: bitonic.cpp common.h
	g++ -c -fopenmp bitonic.cpp
brick.o: brick.cpp common.h
	g++ -c -fopenmp brick.cpp
merge.o: merge.cpp common.h
	g++ -c -fopenmp merge.cpp
quick.o: quick.cpp common.h
	g++ -c -fopenmp quick.cpp
radix.o: radix.cpp common.h
	g++ -c -fopenmp radix.cpp
