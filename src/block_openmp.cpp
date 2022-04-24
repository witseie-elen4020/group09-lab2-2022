#include <iostream>
#include <omp.h>
#include "common_functions.h"

using namespace std;
void block_transpose(int **matrix, int matrix_dim, int block_size,int num_of_threads);
int main(int argc, char* argv[]){

	auto matrix_dim = 0;
	auto num_of_threads = 0;
	auto block_size = 32	;
	
	if(argc == 3){
		matrix_dim = atoi(argv[1]); //Matrix dimension 
		num_of_threads = atoi(argv[2]);
	}
	else{
	 	cout << "Too many or few arguments. Input needs 3 arguments. Default values will be used" << endl;
		matrix_dim = 128;
		num_of_threads = omp_get_max_threads();
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

void block_transpose(int **matrix, int matrix_dim, int block_size,int num_of_threads){

	auto block_dim = block_size;
	auto max_block_size = (matrix_dim / block_dim);
	auto blocks = max_block_size * max_block_size;
	int placeholder = 0;
	double start = 0;
	double end = 0;

	omp_set_num_threads(num_of_threads);
	start = omp_get_wtime();
	#pragma omp parallel
	{	
		transpose_elements(matrix, max_block_size, blocks, block_dim,placeholder);
		#pragma omp barrier
		transpose_blocks(matrix, max_block_size, block_dim,placeholder);
		transponse_edge_blocks(matrix, matrix_dim, block_dim, num_of_threads,placeholder);
	}
	end = omp_get_wtime();
	
	double total = end-start;
	cout << "Time taken: " << total << "s"<<endl; 
}


