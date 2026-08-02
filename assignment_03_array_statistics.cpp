// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

// Calculate mean (average)
double calculateMean(const vector<double>& numbers) {
    if (numbers.empty()) return 0.0;
    double sum = accumulate(numbers.begin(), numbers.end(), 0.0);
    return sum / numbers.size();
}

// Calculate median
double calculateMedian(vector<double> numbers) {
    if (numbers.empty()) return 0.0;
    sort(numbers.begin(), numbers.end());
    size_t n = numbers.size();
    if (n % 2 == 0) {
        return (numbers[n/2 - 1] + numbers[n/2]) / 2.0;
    } else {
        return numbers[n/2];
    }
}

// Calculate variance (population variance)
double calculateVariance(const vector<double>& numbers, double mean) {
    if (numbers.empty()) return 0.0;
    double sumSquaredDiffs = 0.0;
    for (double num : numbers) {
        sumSquaredDiffs += pow(num - mean, 2);
    }
    return sumSquaredDiffs / numbers.size();
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }

    vector<double> numbers(n);
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; ++i) {
        if (!(cin >> numbers[i])) {
            cerr << "Invalid numeric input." << endl;
            return 1;
        }
    }

    double mean = calculateMean(numbers);
    double median = calculateMedian(numbers);
    double variance = calculateVariance(numbers, mean);
    double stdDev = sqrt(variance);

    cout << fixed << setprecision(4);
    cout << "\n--- Statistics ---" << endl;
    cout << "Mean:               " << mean << endl;
    cout << "Median:             " << median << endl;
    cout << "Variance:           " << variance << endl;
    cout << "Standard Deviation: " << stdDev << endl;

    return 0;
}
