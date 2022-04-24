#ifndef COMMON_FUNCTIONS_H
#define COMMON_FUNCTIONS_H

void init_matrix(int **matrix, int N){

	for(auto i = 0; i < N; i++){
		for(auto j = 0; j < N; j++){
			matrix[i][j] = rand()%(N+1);
		}
	}
}

void print2D(int **matrixA, int matrix_dim)
{
    std::cout << "****************************" << std::endl;
    for (int i = 0; i < matrix_dim; i++)
    {
        for (int j = 0; j < matrix_dim; j++)
        {
            std::cout << matrixA[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

void memoryDeAllocation_2D(int ** matrix_ptr, int matrix_leng)
{
    for(auto i = 0; i < matrix_leng; i++)
    {
        delete [] matrix_ptr[i];
    }
    delete [] matrix_ptr;
}

void transpose_elements(int **matrix, int block_size, int num_of_blocks, int block_dim, int thread_number)
{
	/*pragma constructs ignored when block_pthread.cpp runs this file because of the exclusion 
	of the omp header file inside block_pthread.cpp. Without also invoking the #pragma omp parallel in this file
	the execution of the for loop below continues as a single thread*/
	#pragma omp for
	for(auto block = thread_number; block < num_of_blocks; block++){
		auto i_begin = (block/block_size)*block_dim;
		auto i_finish = i_begin + block_dim;
		auto j_begin = (block % block_size)*block_dim;
		auto j_finish = j_begin + block_dim;

		for(auto i = i_begin, j_off = 1; i < i_finish; i++, j_off++){
			for(int j = j_begin + j_off, i_off = 1; j < j_finish; j++, i_off++){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i + i_off][j - i_off];
				matrix[i + i_off][j - i_off] = temp;
			}
		}
	}
}


void transpose_blocks(int **matrix, int block_size, int block_dim,int thread_number)
{
	#pragma omp for
	for(auto first_block = thread_number; first_block < block_size; first_block++){
		for(auto second_block = first_block+1; second_block < block_size; second_block++){
			auto i_begin_1 = first_block * block_dim;
			auto j_begin_1 = (second_block % block_size) * block_dim;
			auto i_begin_2 = j_begin_1;
			auto j_begin_2 = i_begin_1;

			auto i_finish = i_begin_1 + block_dim;
			auto j_finish = j_begin_1 + block_dim;

			for(auto i_1 = i_begin_1, i_2 = i_begin_2; i_1 < i_finish; i_1++, i_2++){
				for(auto j_1 = j_begin_1, j_2 = j_begin_2; j_1 < j_finish; j_1++, j_2++){
					auto temp = matrix[i_1][j_1];
					matrix[i_1][j_1] = matrix[i_2][j_2];
					matrix[i_2][j_2] = temp;
				}	
			}
		}
	}
}

void transponse_edge_blocks(int **matrix, int matrix_dim, int block_dim, int num_of_threads,int thread_number)
{
	if(matrix_dim % block_dim != 0)
	{
		auto edge_index = (matrix_dim - matrix_dim%block_dim);

		#pragma omp for collapse(2)
		for(int i = edge_index+thread_number; i < matrix_dim; i++)
			for(int j = 0; j < matrix_dim; j++)
			{
				auto temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}

		for(int i = edge_index+thread_number; i < matrix_dim; i++)
			for(int j = edge_index; j < i; j++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;				
			}
	}

}



#endif
