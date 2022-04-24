#! /bin/bash

echo ""
echo "Matrix Transposition using Diagonal OpenMP Threading"
echo ""

echo "128x128 matrix, threads are spawned automatically"
../executables/openmp_diagonal 128 4

echo ""
echo "1024x1024 matrix, threads are spwaned automatically"
../executables/openmp_diagonal 1024 4

echo ""
echo "2048x2048 matrix, threads are spawned automatically"
../executables/openmp_diagonal 2048 4

echo ""
echo "4096x4096 matrix, threads are spawned automatically"
../executables/openmp_diagonal 4096 4

echo ""
