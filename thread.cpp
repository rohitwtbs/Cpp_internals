#include <iostream>
#include <thread>

// Function that will be executed by multiple threads
void printNumbers(int start, int end) {
    for (int i = start; i <= end; ++i) {
        std::cout << "Thread ID: " << std::this_thread::get_id() << " prints: " << i << std::endl;
    }
}

int main() {
    // Create multiple threads, each with a different range of numbers
    std::thread t1(printNumbers, 1, 5);  // Thread t1 prints numbers from 1 to 5
    std::thread t2(printNumbers, 6, 10); // Thread t2 prints numbers from 6 to 10

    // Wait for both threads to finish execution
    t1.join();  // Ensures the main thread waits for t1 to complete
    t2.join();  // Ensures the main thread waits for t2 to complete

    std::cout << "Both threads have finished execution." << std::endl;

    return 0;
}
