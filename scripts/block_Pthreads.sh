#! /bin/bash

echo ""
echo "Matrix Transposition using Block Threading PThreads"
echo ""

echo "128x128 matrix using 4 threads"
../executables/pthreads_block 128 4

echo ""
echo "1024x1024 matrix using 4 threads"
../executables/pthreads_block 1024 4

echo ""
echo "2048x2048 matrix using 4 threads"
../executables/pthreads_block 2048 4

echo ""
echo "4096x4096 matrix using 4 threads"
../executables/pthreads_block 4096 4

echo ""
