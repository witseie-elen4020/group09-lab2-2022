#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <pthread.h>
#include "common_functions.h"

using namespace std;

pthread_mutex_t lock;
struct DataStore{
    int thread_id;
    int master_thread_id=0;
    int num_threads;
    int **matrix_A;
    int matrix_size;
};
auto gthread_id=0;

void init_2D_matrices(int **matrixA, int matrix_dim);
void transpose(int **matrixA, int matrix_dim,int num_threads);
void* diagonal_pointer(void *input);
void print2D(int **matrixA, int matrix_dim);

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
    
    DataStore data_;
    data_.matrix_A = new int *[matrixLength];
    for (auto i = 0; i < matrixLength; i++)
    {
        data_.matrix_A[i] = new int[matrixLength];
    }


    init_matrix(data_.matrix_A, matrixLength);
    transpose(data_.matrix_A, matrixLength,num_threads); 
    memoryDeAllocation_2D(data_.matrix_A,matrixLength);

    return 0;
}

void transpose(int **matrixA, int matrix_dim,int num_threads){

    pthread_t threads[num_threads];
    struct DataStore data_store;
    data_store.matrix_A =matrixA;
    data_store.matrix_size =matrix_dim;
    data_store.num_threads =num_threads;
    clock_t start_t, stop_t;

    start_t =clock();
    for (int index = 0; index < num_threads; index++)
        pthread_create(&threads[index], NULL, diagonal_pointer, &data_store);

    for (int index = 0; index < num_threads; index++)
        pthread_join(threads[index], NULL);
    stop_t =clock();
   
    double total = (stop_t - start_t)/double(CLOCKS_PER_SEC);      
    cout << "Took: " << total << " s" << endl;


}
void* diagonal_pointer(void *input)
{
    struct DataStore data = *((struct DataStore*) input);

    pthread_mutex_lock(&lock);
    data.thread_id = gthread_id;
    gthread_id++;
    pthread_mutex_unlock(&lock);

    for(int i = data.thread_id; i < data.matrix_size; i += data.num_threads)
        for (int j = i ; j < data.matrix_size; j++)
        {
            if(i != j){
            int temp = data.matrix_A[i][j];
            data.matrix_A[i][j] = data.matrix_A[j][i];
            data.matrix_A[j][i] = temp;
            }
        }
    pthread_exit(0);
}

