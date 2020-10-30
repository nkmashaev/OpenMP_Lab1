#!/usr/bin/bash

echo "Starting script..."
echo "==========STARTING-SCRIPT==========" > lab1_data.txt

for opt_key in -O0 -O1 -O2 -O3
do
	export OMP_NUM_THREADS=1
	export OMP_SCHEDULE="STATIC,1"
	
	echo ""
	echo "Building binaries with lab1_builder.sh ..."
	echo "=============================="
	./lab1_builder.sh $opt_key
	echo "=============================="
	echo ""

	echo "$opt_key optimization"
	echo "==========$opt_key optimization==========" >> lab1_data.txt
	echo "Calculating consistent_ijk"
	python3 tester.py ./bin/consistent_ijk >> lab1_data.txt
	echo "Calculating consistent_kji"
	python3 tester.py ./bin/consistent_kji >> lab1_data.txt
	echo "Starting parallel tests"
	for var in 1 2 3 4 5 6 7 8
	do
		export OMP_NUM_THREADS=$var
		echo "THREAD_NUMB = $OMP_NUM_THREADS" 
		echo "==========THREAD_NUMB is $OMP_NUM_THREADS==========" >> lab1_data.txt
		echo "Calculating pure_for_1"
		python3 tester.py ./bin/pure_for_1 >> lab1_data.txt
		echo "Calculating pure_for_2"
		python3 tester.py ./bin/pure_for_2 >> lab1_data.txt
		echo "Calculating pure_for_3"
		python3 tester.py ./bin/pure_for_3 >> lab1_data.txt
		echo "Calculating collapse_1"
		python3 tester.py ./bin/collapse_1 >> lab1_data.txt
		echo "Calculating collapse_2"
		python3 tester.py ./bin/collapse_2 >> lab1_data.txt
		echo "Calculating collapse_3"
		python3 tester.py ./bin/collapse_3 >> lab1_data.txt
		echo "Calculation sections"
		python3 tester.py ./bin/sections >> lab1_data.txt
	done
	
	echo ""
	export OMP_NUM_THREADS=4
	echo "THREAD_NUMB = $OMP_NUM_THREADS" 
        echo "==========THREAD_NUMB is $OMP_NUM_THREADS==========" >> lab1_data.txt

	for method in STATIC DYNAMIC GUIDED
	do
		echo "==========METHOD is $method==========" >> lab1_data.txt
		for chunk in 1 10 50 100
		do
			echo "==========CHUNK_SIZE is $chunk==========" >> lab1_data.txt
			export OMP_SCHEDULE="$method,$chunk"
			echo "METHOD is $OMP_SCHEDULE"
			echo "Calculating pure_for_1"
                	python3 tester.py ./bin/pure_for_1 >> lab1_data.txt
                	echo "Calculating pure_for_2"
                	python3 tester.py ./bin/pure_for_2 >> lab1_data.txt
                	echo "Calculating pure_for_3"
                	python3 tester.py ./bin/pure_for_3 >> lab1_data.txt
                	echo "Calculating collapse_1"
                	python3 tester.py ./bin/collapse_1 >> lab1_data.txt
               		echo "Calculating collapse_2"
                	python3 tester.py ./bin/collapse_2 >> lab1_data.txt
                	echo "Calculating collapse_3"
                	python3 tester.py ./bin/collapse_3 >> lab1_data.txt
		done
	done

	echo ""
        export OMP_NUM_THREADS=4
        echo "THREAD_NUMB = $OMP_NUM_THREADS"
        echo "==========THREAD_NUMB is $OMP_NUM_THREADS==========" >> lab1_data.txt
	
	for method in STATIC DYNAMIC GUIDED
        do
                echo "==========METHOD is $method==========" >> lab1_data.txt
                for chunk in 1000 100000 500000
                do
                        echo "==========CHUNK_SIZE is $chunk==========" >> lab1_data.txt
                        export OMP_SCHEDULE="$method,$chunk"
                        echo "METHOD is $OMP_SCHEDULE"
                        echo "Calculating collapse_1"
                        python3 tester.py ./bin/collapse_1 >> lab1_data.txt
                        echo "Calculating collapse_2"
                        python3 tester.py ./bin/collapse_2 >> lab1_data.txt
                        echo "Calculating collapse_3"
                        python3 tester.py ./bin/collapse_3 >> lab1_data.txt
                done
        done

done
