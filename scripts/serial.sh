#! /bin/bash

echo ""
echo "Matrix Transposition using Serial programming"
echo ""

echo "128x128 matrix"
../executables/serial 128 4

echo ""
echo "1024x1024 matrix"
../executables/serial 1024 4

echo ""
echo "2048x2048 matrix"
../executables/serial 2048 4

echo ""
echo "4096x4096 matrix"
../executables/serial 4096 4
echo ""
