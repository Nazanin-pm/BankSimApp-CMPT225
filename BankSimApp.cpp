
#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"
#include "Event.h"
#include "BinaryHeap.h"

// Function to process the input file and simulate the bank system
void simulateBankSystem(const std::string& inputFile) {
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return;
    }

    PriorityQueue<Event> eventQueue;
    int totalCustomers = 0;
    double totalWaitingTime = 0.0;

    int currentTime = 0;
    int arrivalTime, transactionTime;
    while (file >> arrivalTime >> transactionTime) {
        Event arrival('A', arrivalTime, transactionTime);
        eventQueue.enqueue(arrival);
    }

    std::cout << "Simulation Begins" << std::endl;

    while (!eventQueue.isEmpty()) {
        Event currentEvent = eventQueue.peek();
        eventQueue.dequeue();

        currentTime = currentEvent.getTime();

        if (currentEvent.getType() == 'A') {
            // Arrival event
            totalCustomers++;
            std::cout << "Processing an arrival event at time: " << currentTime << std::endl;

            // Calculate waiting time
            int waitingTime = currentTime - currentEvent.getTime();
            totalWaitingTime += waitingTime;

            // Create departure event
            Event departure('D', currentTime + currentEvent.getLength());
            eventQueue.enqueue(departure);
        } else {
            // Departure event
            std::cout << "Processing a departure event at time: " << currentTime << std::endl;
        }
    }

    std::cout << "Simulation Ends" << std::endl;

    // Compute statistics
    double averageWaitingTime = totalWaitingTime / totalCustomers;

    // Output statistics
    std::cout << "\nFinal Statistics:" << std::endl;
    std::cout << "Total number of people processed: " << totalCustomers << std::endl;
    std::cout << "Average amount of time spent waiting: " << averageWaitingTime << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    simulateBankSystem(inputFile);
    return 0;
}
