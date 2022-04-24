##group09-lab2-2022

##ELEN4020 LAb2 - 2D Matrix transposition

### This a 2D  matrix transposition programs using parallel programming

The programs perform a parallel execution of matrix transposition in 2D and 3D
Each file in the **src** implements one of the following functions:

-common_functions: this class header file emphacises the OOP of the code by including all function
                   that are common within the different algorithms 
-block_openmp: 2D transposition PThreads
-block_openmp: 2D transposition OpenMP
-diagonal_openmp: 2D transposition PThreads
-block_openmp: 2D transposition OpenMP
-naive_openmp: 2D transposition OpenMP
-serial: 2D transposition 

Only the transposition computational part of the code in all source files is timed and displayed
onto the terminal

## Compile Instructions
the source code is compiled in either one of the following ways two ways, and the following
should be considered when tying to run and compile programms:

-C++ has been used in developing the code
-Ubuntu linux version is 18.04 LTS (WSL in Windows 10)
-The compiler is g++ version 7.4.0
-The GNU make version is 4.1
-The editor is VIM - Vi 8.0 and Git nano latest version

### Method 1
*1* Clone the repository into local directory.
*2* Access/open the <scripts> folder found within the local-directroy\Ugroup09-lab2-2022\scripts in  ubuntu terminal commandline 
*3* Run the <executeCode.sh> file by typing the following command in ubuntu terminal: <./executeCode.sh> , hit {note* : exclude/remove the '<' & '>' in all commands}
    - If the terminal does not allow permission to run the <executeCode.sh> file then type: <chmod +x executeCode.sh> hit enter
      then <./executeCode.sh> 	
*3* This should automatically run the Makefile located in the <executables> folder.
*4* The Makefile will compiles all source code located in the <src> folder and produce the respective object files into the <executables> folder
*5* After all compilation by the Makefile, the <executeCode.sh> file will then run the object files and print the execution times of the algorithms on the ubuntu terminal

### Method2
*1* Clone the repository into local directory.
*2* Access/open the <scripts> folder found within the local-directroy\Ugroup09-lab1-2022\scripts in  git bash terminal commandline
*3* Run the <executeCode.sh> file by typing the following command in git bash terminal: <./executeCode.sh> , hit enter{not*, to exclude the '<' & '>' in all commands}
    - If the terminal does not allow permission to run the <executeCode.sh> file then type: <chmod +x executeCode.sh> hit enter
      then <./executeCOde.sh>
    - Make sure your git bash terminal has the command <make> installed and working or else you will get an error using this method
*3* This should automatically run the Makefile located in the <executables> folder.
*4* The Makefile will compiles all source code located in the <src> folder and produce the respective object files into the <executables> folder
*5* After all compilation by the Makefile, the <executeCode.sh> file will then run the object files and print the execution times of the algorithms on the ubuntu terminal


##If you intend to run each executable individually, use the following command:

<./{executable name} {matrix size} {number of threads}>

an example of running the naive code is given below
_Example:_  <./naive_OpenMP 128 4>

remember to remove the braces  '<' '>'. 

please be patient, it could take up to 3minutes for code to compile and run object files to print execution times of various matrix sizes.
