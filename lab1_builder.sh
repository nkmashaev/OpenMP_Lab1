#!/usr/bin/bash

op_key="-O0"
if [ $# -ge 1 ]
then
	op_key=$1
fi
echo "Optimization key is $op_key"

#Creating bin directory
echo "Start Lab1 Building..."
if ! [ -d ./bin ]
then
	mkdir bin
fi
cd bin

#Creating temporary files
echo "Creating *.o files..."
g++ -c ../GridReader/grid_reader.cpp -Wall $op_key
g++ -c ../ConsistentSolution/consistent_ijk.cpp -Wall $op_key
g++ -c ../ConsistentSolution/consistent_kji.cpp -Wall $op_key
g++ -fopenmp -c ../ParallelSolution/collapse/collapse_1.cpp -Wall $op_key
g++ -fopenmp -c ../ParallelSolution/collapse/collapse_2.cpp -Wall $op_key
g++ -fopenmp -c ../ParallelSolution/collapse/collapse_3.cpp -Wall $op_key
g++ -fopenmp -c ../ParallelSolution/omp_for/parallel_for_1.cpp -Wall $op_key
g++ -fopenmp -c ../ParallelSolution/omp_for/parallel_for_2.cpp -Wall $op_key
g++ -fopenmp -c ../ParallelSolution/omp_for/parallel_for_3.cpp -Wall $op_key
g++ -fopenmp -c ../ParallelSolution/omp_sections/sections.cpp -Wall $op_key

#Creating executable
echo "Creating bin files..."
g++ -o consistent_ijk consistent_ijk.o grid_reader.o -Wall $op_key
g++ -o consistent_kji consistent_kji.o grid_reader.o -Wall $op_key
g++ -fopenmp -o collapse_1 collapse_1.o grid_reader.o -Wall $op_key
g++ -fopenmp -o collapse_2 collapse_2.o grid_reader.o -Wall $op_key
g++ -fopenmp -o collapse_3 collapse_3.o grid_reader.o -Wall $op_key
g++ -fopenmp -o pure_for_1 parallel_for_1.o grid_reader.o -Wall $op_key
g++ -fopenmp -o pure_for_2 parallel_for_2.o grid_reader.o -Wall $op_key
g++ -fopenmp -o pure_for_3 parallel_for_3.o grid_reader.o -Wall $op_key
g++ -fopenmp -o sections sections.o grid_reader.o -Wall $op_key

#Delete temp files
echo "Deleting temporary .o files..."
rm *.o

echo "Done..."
cd ..
