# PRODUCER-CONSUMER

I have written the Producer-Consumer code in C++20. Please update your g++ (GCC) compiler to a version that supports C++20 features.

The input file will contain the following:
1. Sleep time (in seconds)
2. Number of producers
3. Number of consumers

The output file will contain the following:
1. Sleep time (in seconds)
2. Number of producers
3. Number of consumers
4. Turnaround time (in milliseconds)

The outline of the Producer-Consumer code is as follows:
1. Open the input file input-2sec-wait.txt.
2. Open the output file output-2sec-wait.txt.
3. Print the header line to the output file.
4. While there are still lines to read from the input file:
    1. Print the sleep time to the console.
    2. Print the number of producers to the console.
    3. Print the number of consumers to the console.
    4. Record the start time.
    5. Create an array to store the producer threads.
    6. Create an array to store the consumer threads.
    7. Create the producer threads:
        1. Call the producer function to produce numbers in the buffer.
        2. Print the number produced by the producer thread to the console.
    8. Create the consumer threads:
        1. Call the consumer function to consume numbers in the buffer.
        2. Print the number consumed by the consumer thread to the console.
    9. Put the threads to sleep for a specified duration.
    10. Wait for all producer threads to finish.
    11. Wait for all consumer threads to finish.
    12. Record the end time.
    13. Calculate the turnaround time (in milliseconds).
    14. Print the results to the output file.
5. Close the input file input-2sec-wait.txt.
6. Close the output file output-2sec-wait.txt.

Please change the input and output file names to test different sleep times:
1. input-4sec-wait.txt and output-4sec-wait.txt
2. input-6sec-wait.txt and output-6sec-wait.txt

Please use the following commands to run the producerConsumer.cpp file:
1. g++ -std=c++20 -o producerConsumer producerConsumer.cpp
2. ./producerConsumer
