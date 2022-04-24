#include <iostream>
#include <cstdlib>
#include <omp.h>
#include "common_functions.h"

using namespace std;

void transpose(int **matrixA, int matrix_dim);

int main(int argc, char *argv[])
{

    auto num_threads = 0;
    auto matrixLength = 0;
    if (argc == 3)
    {
    	matrixLength = atoi(argv[1]);
        num_threads = atoi(argv[2]);
        
    }
    else
    {
        printf("Invalid run arguments\n");
        return -1;
    }
    
    int **matrixA = new int *[matrixLength];
    for (auto i = 0; i < matrixLength; i++)
    {
        matrixA[i] = new int[matrixLength];
    }

    init_matrix(matrixA, matrixLength);
    transpose(matrixA, matrixLength);
    memoryDeAllocation_2D(matrixA,matrixLength);

    return 0;
}

void transpose(int **matrixA, int matrix_dim)
{
    int i = 0, j = 0;
    auto start = omp_get_wtime();
    #pragma omp parallel for private(i,j)
    for (i = 0; i < matrix_dim; i++)
    {
        for (j = i; j < matrix_dim; j++)
        {
                if (i != j){
                int temp = matrixA[i][j];
                matrixA[i][j] = matrixA[j][i];
                matrixA[j][i] = temp;
                }
        }
    }
    auto stop = omp_get_wtime();
    cout << "Took: " << (stop-start) << " s" << endl;    
}

