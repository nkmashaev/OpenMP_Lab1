import subprocess
import os
import sys

if __name__ == "__main__":
    iter_numb = 100
    file_name = sys.argv[1]
    
    
    min_time = 0.0
    max_time = 0.0
    total_time = 0.0
    average = 0.0
    for i in range(iter_numb):
        process = subprocess.Popen(file_name,
                                   stdout=subprocess.PIPE)
        stdout, stderr = process.communicate()
        exec_time = float(stdout.decode().split()[2])
        process.wait()
       
        total_time += exec_time
        if i == 0 or min_time > exec_time:
            min_time = exec_time
        if max_time < exec_time:
            max_time = exec_time

    average = total_time / iter_numb
    name = file_name.split('/')[-1]
    print(name.ljust(20, ' '), 
          '{:.11E}'.format(min_time).center(20, ' '),
          '{:.11E}'.format(max_time).center(20, ' '),
          '{:.11E}'.format(average).center(20, ' '),
          sep='|')    
