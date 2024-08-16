#include <iostream>
#include <string>
#include <climits>

using namespace std;

class QuickSums {
public:
    int minSums(string numbers, int sum) {
        int result = minSumsHelper(numbers, sum, 0, 0, 0);
        // If result is INT_MAX then it means no valid solution was found, so return -1
        return result == INT_MAX ? -1 : result;
    }

    // Helper method to try every possible way to insert plus signs
    int minSumsHelper(const string& numbers, int target, int pos, int currentSum, int additions) {
        // Base case
        if (pos == numbers.length()) {
            // Check if the current sum equals target
            return (currentSum == target) ? additions : INT_MAX;
        }

        int result = INT_MAX;
        int num = 0;

        // Try forming numbers by adding consecutive digits and recursively checking the rest of the string
        for (int i = pos; i < numbers.length(); ++i) {
            // Build current number by appending next digit
            num = num * 10 + (numbers[i] - '0');

            // Recursively check next part of string, updating current sum and the number of additions
            result = min(result, minSumsHelper(numbers, target, i + 1, currentSum + num, additions + (pos != 0)));
        }

        return result;
    }
};