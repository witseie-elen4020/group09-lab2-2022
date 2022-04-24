echo "Compiling Source Codes"
cd ..
cd executables
make
cd ../scripts


echo ""
echo "compiling Naive_OpenMP Source Code"
echo ""
chmod +x naive_OpenMP.sh
./naive_OpenMP.sh

echo ""
echo "compiling Diagonal_PThreads Source Code"
echo ""
chmod +x diagonal_Pthreads.sh
./diagonal_Pthreads.sh

echo ""
echo "compiling Diagonal_OpenMP Source Code"
echo ""
chmod +x diagonal_OpenMP.sh
./diagonal_OpenMP.sh

echo ""
echo "compiling Block_PThreads Source Code"
echo ""
chmod +x block_Pthreads.sh
./block_Pthreads.sh

echo ""
echo "compiling Block_OpenMP Source Code"
echo ""
chmod +x block_OpenMP.sh
./block_OpenMP.sh

echo ""
echo "compiling serial Source Code"
echo ""
chmod +x serial.sh
./serial.sh
