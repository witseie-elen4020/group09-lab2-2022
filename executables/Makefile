# -*- MakeFile -*-

all: openmp_naive openmp_diagonal openmp_block pthread_diagonal pthread_block serial

openmp_naive: ../src/naive_openmp.cpp
	g++ ../src/naive_openmp.cpp -fopenmp -o openmp_naive
	
openmp_diagonal: ../src/diagonal_openmp.cpp
	g++ ../src/diagonal_openmp.cpp -fopenmp -o openmp_diagonal
	
openmp_block: ../src/block_openmp.cpp
	g++ ../src/block_openmp.cpp -fopenmp -o openmp_block
	
pthread_diagonal: ../src/diagonal_pthread.cpp
	g++ ../src/diagonal_pthread.cpp -lpthread -o pthreads_diagonal
	
pthread_block: ../src/block_pthread.cpp
	g++ ../src/block_pthread.cpp -lpthread -o pthreads_block
	
serial: ../src/serial.cpp
	g++ ../src/serial.cpp -fopenmp -o serial
	
clean:
	rm openmp_naive openmp_diagonal openmp_block pthreads_diagonal pthreads_block
