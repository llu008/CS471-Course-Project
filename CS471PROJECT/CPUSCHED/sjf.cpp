#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define ARRAY_SIZE 500 // Number of processes to simulate

using namespace std;

// Structure of each process
struct Process {
    int arrival; // Arrival time of the process
    int burst; // Burst time of the process
    int completion; // Completion time of the process
    int turnaround; // Turnaround time of the process
    int waiting; // Waiting time of the process
    int start; // Start time of the process
    int response; // Response time of the process
};

// Function to sort all processes by their arrival time
bool sortArrivalTime(const Process& process1, const Process& process2) {
    return process1.arrival < process2.arrival;
}

// Function to sort all processes by their burst time
bool sortBurstTime(const Process& process1, const Process& process2) {
    return process1.burst < process2.burst;
}

// Function to calculate the total burst time of all processes
int calculateTotalBurstTime(Process process[]) {
    int totalBurstTime = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        totalBurstTime += process[i].burst;
    }
    return totalBurstTime;
}

// Function to calculate the total waiting time of all processes
int calculateTotalWaitingTime(Process process[]) {
    int totalWaitingTime = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        totalWaitingTime += process[i].waiting;
    }
    return totalWaitingTime;
}

// Function to calculate the total turnaround time of all processes
int calculateTotalTurnaroundTime(Process process[]) {
    int totalTurnaroundTime = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        totalTurnaroundTime += process[i].turnaround;
    }
    return totalTurnaroundTime;
}

// Function to calculate the total response time of all processes
int calculateTotalResponseTime(Process process[]) {
    int totalResponseTime = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        totalResponseTime += process[i].response;
    }
    return totalResponseTime;
}

int main() {
    Process process[ARRAY_SIZE]; // Array to store all processes

    ifstream inputFile;
    inputFile.open("Datafile1-txt.txt"); // Open the input file
    string header;
    getline(inputFile, header); // Read the header line (not used)
    for (int i = 0; i < ARRAY_SIZE; i++) {
        inputFile >> process[i].arrival; // Read the arrival time of the process
        inputFile >> process[i].burst; // Read the burst time of the process
    }
    inputFile.close(); // Close the input file

    sort(process, process + ARRAY_SIZE, sortArrivalTime); // Sort all processes by their arrival time

    vector<Process> queue; // Queue to manage processes
    int time = 0; // Current time in the simulation
    int completed = 0; // Number of completed processes
    int index = 0; // Index to keep track of the process that is next to arrive
    while (completed < ARRAY_SIZE) {
        while (index < ARRAY_SIZE && process[index].arrival <= time) { // Check if the process has arrived before or at the current time
            queue.push_back(process[index]); // Add the process to the queue
            index++; // Increment the index
        }
        if (!queue.empty()) {
            sort(queue.begin(), queue.end(), sortBurstTime); // Sort all processes in the queue by their burst time
            process[completed] = queue.front(); // Update the process array with the shortest burst time
            time += queue.front().burst; // Add the burst time of the selected process to the current time
            queue.erase(queue.begin()); // Remove the selected process from the queue
            completed++; // Increment the number of completed processes
        } else {
            time++; // Increment the current time if no process is ready
        }
    }

    process[0].start = process[0].arrival;
    process[0].completion = process[0].arrival + process[0].burst;
    for (int i = 1; i < ARRAY_SIZE; i++) {
        process[i].start = max(process[i - 1].completion, process[i].arrival); // Start time = max(previous completion time, current arrival time)
        process[i].completion = process[i].start + process[i].burst; // Completion time = start time + burst time
    }
    for (int i = 0; i < ARRAY_SIZE; i++) {
        process[i].turnaround = process[i].completion - process[i].arrival; // Turnaround time = completion time - arrival time
        process[i].waiting = process[i].turnaround - process[i].burst; // Waiting time = turnaround time - burst time
        process[i].response = process[i].start - process[i].arrival; // Response time = start time - arrival time
    }

    int totalBurstTime = calculateTotalBurstTime(process); // Calculate the total burst time of all processes
    int totalWaitingTime = calculateTotalWaitingTime(process); // Calculate the total waiting time of all processes
    int totalTurnaroundTime = calculateTotalTurnaroundTime(process); // Calculate the total turnaround time of all processes
    int totalResponseTime = calculateTotalResponseTime(process); // Calculate the total response time of all processes

    ofstream outputFile;
    outputFile.open("sjf-output.txt"); // Open the output file
    outputFile << "Number of processes: " << ARRAY_SIZE << endl;
    outputFile << "Total elapsed time (for the scheduler): " << process[ARRAY_SIZE - 1].completion << endl;
    outputFile << "Throughput (number of processes executed in one unit of CPU burst time): "
               << static_cast<double>(totalBurstTime) / ARRAY_SIZE << endl;
    outputFile << "CPU utilization: " << (static_cast<double>(totalBurstTime) / process[ARRAY_SIZE - 1].completion) * 100 << "%" << endl;
    outputFile << "Average waiting time (in CPU burst times): " << static_cast<double>(totalWaitingTime) / ARRAY_SIZE << endl;
    outputFile << "Average turnaround time (in CPU burst times): " << static_cast<double>(totalTurnaroundTime) / ARRAY_SIZE << endl;
    outputFile << "Average response time (in CPU burst times): " << static_cast<double>(totalResponseTime) / ARRAY_SIZE << endl;
    outputFile.close(); // Close the output file

    return 0;
}

/*
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << "AT = " << process[i].arrival << ", "
             << "BT = " << process[i].burst << ", "
             << "CT = " << process[i].completion << ", "
             << "TAT = " << process[i].turnaround << ", "
             << "WT = " << process[i].waiting << ", "
             << "ST = " << process[i].start << ", "
             << "RT = " << process[i].response << endl;
    }
*/
