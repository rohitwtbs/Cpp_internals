#include <iostream>
using namespace std;

// Class to check prime numbers
class PrimeChecker {
public:
    // Method to check if a number is prime
    bool isPrime(int n) {
        // Corner cases
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        // Check divisibility from 5 to √n
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int number;
    PrimeChecker primeChecker;  // Create an object of PrimeChecker class

    // Ask the user for input
    cout << "Enter a number: ";
    cin >> number;

    // Use the class method to check if the number is prime
    if (primeChecker.isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }

    return 0;
}
