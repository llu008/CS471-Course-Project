#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <mutex>
#include <semaphore>
#include <iomanip>

#define BUFFER_SIZE 525

std::mutex mutex;
std::counting_semaphore<BUFFER_SIZE> empty(BUFFER_SIZE); // Initialize the empty semaphore to BUFFER_SIZE
std::counting_semaphore<BUFFER_SIZE> full(0); // Initialize the full semaphore to 0

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

// Function to produce numbers in the buffer
int insertItem(int item) {
    empty.acquire(); // Wait for an empty slot
    mutex.lock();
    buffer[in] = item;
    std::cout << "Producer produced " << item << std::endl;
    in = (in + 1) % BUFFER_SIZE;
    mutex.unlock();
    full.release(); // Signal a filled slot
    return 0;
}

// Function to consume numbers in the buffer
int removeItem(int* item) {
    full.acquire(); // Wait for a filled slot
    mutex.lock();
    *item = buffer[out];
    std::cout << "Consumer consumed " << *item << std::endl;
    out = (out + 1) % BUFFER_SIZE;
    mutex.unlock();
    empty.release(); // Signal an empty slot
    return 0;
}

void producer() {
    int producerCounter = 0;
    int item;
    while (producerCounter < 12) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Sleep for 100 milliseconds
        item = rand() % 100; // Random number from 0 to 99
        insertItem(item);
        producerCounter++;
    }
}

void consumer() {
    int consumerCounter = 0;
    int item;
    while (consumerCounter < 12) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Sleep for 100 milliseconds
        removeItem(&item);
        consumerCounter++;
    }
}

int main() {
    int sleepTime;
    int numberOfProducers;
    int numberOfConsumers;

    std::ifstream inputFile;
    inputFile.open("input-6sec-wait.txt"); // Open the input file
    std::ofstream outputFile;
    outputFile.open("output-6sec-wait.txt"); // Open the output file

    outputFile << std::left << std::setw(28) << "Sleep time (in seconds)"
               << std::setw(24) << "Number of producers"
               << std::setw(24) << "Number of consumers" << "Turnaround time (in milliseconds)" << std::endl;

    while (inputFile >> sleepTime >> numberOfProducers >> numberOfConsumers) {
        std::cout << sleepTime << std::endl;
        std::cout << numberOfProducers << std::endl;
        std::cout << numberOfConsumers << std::endl;

        auto start = std::chrono::high_resolution_clock::now(); // Record the start time

        std::thread producerThread[numberOfProducers]; // Array to store producer threads
        std::thread consumerThread[numberOfConsumers]; // Array to store consumer threads

        for (int i = 0; i < numberOfProducers; i++) {
            producerThread[i] = std::thread(producer); // Create the producer threads
        }

        for (int i = 0; i < numberOfConsumers; i++) {
            consumerThread[i] = std::thread(consumer); // Create the consumer threads
        }

        std::this_thread::sleep_for(std::chrono::seconds(sleepTime));

        for (int i = 0; i < numberOfProducers; i++) {
            producerThread[i].join(); // Wait for all producer threads to finish
        }

        for (int i = 0; i < numberOfConsumers; i++) {
            consumerThread[i].join(); // Wait for all consumer threads to finish
        }

        auto end = std::chrono::high_resolution_clock::now(); // Record the end time
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0;

        outputFile << std::left << std::setw(28) << sleepTime
                   << std::setw(24) << numberOfProducers
                   << std::setw(24) << numberOfConsumers << duration << std::endl;
    }

    inputFile.close(); // Close the input file
    outputFile.close(); // Close the output file

    return 0;
}
