// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>
#include <vector>

using namespace std;

// Part 1: Generate Fibonacci sequence up to n terms and return as a vector
vector<unsigned long long> generateFibonacci(int n) {
    vector<unsigned long long> fibSequence;
    if (n <= 0) return fibSequence;

    fibSequence.push_back(0);
    if (n == 1) return fibSequence;

    fibSequence.push_back(1);
    for (int i = 2; i < n; ++i) {
        fibSequence.push_back(fibSequence[i-1] + fibSequence[i-2]);
    }
    return fibSequence;
}

// Part 2: Print the Fibonacci sequence from a vector
void printFibonacci(const vector<unsigned long long>& fibSequence) {
    for (unsigned long long num : fibSequence) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int terms;
    cout << "Enter the number of Fibonacci terms to generate: ";
    cin >> terms;

    if (terms <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    vector<unsigned long long> fibonacci = generateFibonacci(terms);
    cout << "Fibonacci sequence:" << endl;
    printFibonacci(fibonacci);

    return 0;
}
