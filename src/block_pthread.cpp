#include <iostream>
#include <pthread.h>
#include <ctime>
#include <mutex>
#include "common_functions.h"

using namespace std;
//barrier to wait for element transposition in each block to finish so that transposition of the blocks can begin
pthread_barrier_t barrier;
//mutex to lock update in the thread number
pthread_mutex_t lock_thread_number;

void block_transpose(int **matrix, int matrix_dim, int num_of_threads, int block_size);
void* transpose(void *struct_input);

struct matrix_properties {
	int **matrix;
	int matrix_dim;
	int num_of_threads;
	int block_size;
	int thread_number;
};

int main(int argc, char* argv[]){

	auto matrix_dim = 0;
	auto num_of_threads = 0;
	auto block_size = 16;
	
	if(argc == 3){
		matrix_dim = atoi(argv[1]); //Matrix dimension 
		num_of_threads = atoi(argv[2]);
	}
	else{
	 	cout << "Too many or few arguments. Input needs 3 arguments. Default values will be used" << endl;
		matrix_dim = 128;
		num_of_threads = 4;
	}
	
	int** matrix;
	matrix = new int* [matrix_dim];
	
	for(int i = 0;i < matrix_dim;i++){
     		matrix[i] = new int[matrix_dim];
	}
	
	init_matrix(matrix,matrix_dim);
	block_transpose(matrix,matrix_dim,block_size,num_of_threads);
	memoryDeAllocation_2D(matrix,matrix_dim);
}

void* transpose(void *struct_input)
{
	auto thread_number = 0;
	struct matrix_properties my_matrix = *((struct matrix_properties*) struct_input); 
	
	pthread_mutex_lock(&lock_thread_number);
	thread_number = my_matrix.thread_number;
	my_matrix.thread_number++;
	pthread_mutex_unlock(&lock_thread_number);

	auto max_block_size = (my_matrix.matrix_dim / my_matrix.block_size);
	auto num_of_blocks = max_block_size * max_block_size;

	transpose_elements(my_matrix.matrix, max_block_size, num_of_blocks, my_matrix.block_size, thread_number);
	pthread_barrier_wait(&barrier);//wait for other blocks to finish their element transpositions
	transpose_blocks(my_matrix.matrix, max_block_size, my_matrix.block_size, thread_number);
	transponse_edge_blocks(my_matrix.matrix, my_matrix.matrix_dim, my_matrix.block_size, my_matrix.num_of_threads, thread_number);

	pthread_exit(0);
}

void block_transpose(int **matrix, int matrix_dim, int num_of_threads, int block_size)
{
	struct matrix_properties my_matrix;
	my_matrix.matrix = matrix;
	my_matrix.matrix_dim = matrix_dim;
	my_matrix.num_of_threads = num_of_threads;
	my_matrix.block_size = block_size;
	my_matrix.thread_number = 0;
	clock_t start_t, end_t; 
	double total = 0;

	pthread_t my_threads[num_of_threads];
	pthread_barrier_init(&barrier, NULL, num_of_threads);
	
	start_t = clock(); 
	for(auto i = 0; i < num_of_threads; i++){
		pthread_create(&my_threads[i], NULL, transpose, &my_matrix);
	}

	for(auto i = 0; i < num_of_threads; i++){
		pthread_join(my_threads[i], NULL);
	}
	
	pthread_mutex_destroy(&lock_thread_number);
	pthread_barrier_destroy(&barrier);
	
	end_t = clock();
	total = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	cout << "Time taken: " << total << "s"<<endl;
}

