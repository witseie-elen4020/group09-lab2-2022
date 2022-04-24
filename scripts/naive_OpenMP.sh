#! /bin/bash

echo ""
echo "Matrix Transposition using Naive Threading OpenMP"
echo ""

echo "128x128 matrix, system automatically spawns the n0# threads required"
../executables/openmp_naive 128 0

echo ""
echo "1024x1024 matrix,  system automatically spawns the n0# threads required"
../executables/openmp_naive 1024 0

echo ""
echo "2048x2048 matrix,  system automatically spawns the n0# threads required"
../executables/openmp_naive 2048 0

echo ""
echo "4096x4096 matrix,  system automatically spawns the n0# threads required"
../executables/openmp_naive 4096 0

echo ""
