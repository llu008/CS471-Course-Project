# FIFO

I have written the FIFO code in C++11. Please update your g++ (GCC) compiler to a version that supports C++11 features.

The input file will contain the following:
1. Arrival time
2. Burst time

The output file will contain the following:
1. Number of processes
2. Total elapsed time
3. Throughput (Total burst time / Number of processes)
4. CPU utilization (Total burst time / Total elapsed time)
5. Average waiting time (Total waiting time / Number of processes)
6. Average turnaround time (Total turnaround time / Number of processes)
7. Average response time (Total response time / Number of processes)

The outline of the FIFO code is as follows:
1. Create an array to store all 500 processes.
2. Open the input file Datafile1-txt.txt.
3. Read the header line of the input file (not used).
4. For all 500 processes:
    1. Read the arrival time.
    2. Read the burst time.
5. Close the input file Datafile1-txt.txt.
6. Sort all 500 processes by their arrival time.
7. Initialize the start time of the first process.
8. Initialize the completion time of the first process.
9. For the remaining 499 processes:
    1. Calculate the start time.
    2. Calculate the completion time.
10. For all 500 processes:
    1. Calculate the turnaround time.
    2. Calculate the waiting time.
    3. Calculate the response time.
11. Calculate the total burst time of all 500 processes.
12. Calculate the total waiting time of all 500 processes.
13. Calculate the total turnaround time of all 500 processes.
14. Calculate the total response time of all 500 processes.
15. Open the output file fifo-output.txt.
16. Print the number of processes to the output file.
17. Print the total elapsed time to the output file.
18. Calculate and print the throughput to the output file.
19. Calculate and print the CPU utilization to the output file.
20. Calculate and print the average waiting time to the output file.
21. Calculate and print the average turnaround time to the output file.
22. Calculate and print the average response time to the output file.
23. Close the output file fifo-output.txt.

Please use the following commands to run the fifo.cpp file:
1. g++ -std=c++11 -o fifo fifo.cpp
2. ./fifo

# SJF

I have written the SJF code in C++11. Please update your g++ (GCC) compiler to a version that supports C++11 features.

The input file will contain the following:
1. Arrival time
2. Burst time

The output file will contain the following:
1. Number of processes
2. Total elapsed time
3. Throughput (Total burst time / Number of processes)
4. CPU utilization (Total burst time / Total elapsed time)
5. Average waiting time (Total waiting time / Number of processes)
6. Average turnaround time (Total turnaround time / Number of processes)
7. Average response time (Total response time / Number of processes)

The outline of the SJF code is as follows:
1. Create an array to store all 500 processes.
2. Open the input file Datafile1-txt.txt.
3. Read the header line of the input file (not used).
4. For all 500 processes:
    1. Read the arrival time.
    2. Read the burst time.
5. Close the input file Datafile1-txt.txt.
6. Sort all 500 processes by their arrival time.
7. Create a queue to manage all 500 processes.
8. While the number of completed processes is less than 500:
    1. While the process has arrived before or at the current time:
        1. Add the process to the queue.
        2. Increment the index.
    2. If the queue is not empty:
        1. Sort all processes in the queue by their burst time.
        2. Update the process array with the shortest burst time.
        3. Add the burst time of the selected process to the current time.
        4. Remove the selected process from the queue.
        5. Increment the number of completed processes.
    3. Else:
        1. Increment the current time if no process is ready.
9. Initialize the start time of the first process.
10. Initialize the completion time of the first process.
11. For the remaining 499 processes:
    1. Calculate the start time.
    2. Calculate the completion time.
12. For all 500 processes:
    1. Calculate the turnaround time.
    2. Calculate the waiting time.
    3. Calculate the response time.
13. Calculate the total burst time of all 500 processes.
14. Calculate the total waiting time of all 500 processes.
15. Calculate the total turnaround time of all 500 processes.
16. Calculate the total response time of all 500 processes.
17. Open the output file sjf-output.txt.
18. Print the number of processes to the output file.
19. Print the total elapsed time to the output file.
20. Calculate and print the throughput to the output file.
21. Calculate and print the CPU utilization to the output file.
22. Calculate and print the average waiting time to the output file.
23. Calculate and print the average turnaround time to the output file.
24. Calculate and print the average response time to the output file.
25. Close the output file sjf-output.txt.

Please use the following commands to run the sjf.cpp file:
1. g++ -std=c++11 -o sjf sjf.cpp
2. ./sjf
