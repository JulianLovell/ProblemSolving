#include <iostream>
#include <cmath>

using namespace std;

class MinimalDifference {
public:
    // Helper function to calculate the digit sum of a number
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int findNumber(int A, int B, int C) {
        // Calculate the digit sum of C
        int goalDigitSum = digitSum(C);
        
        int closest = A;
        // Starting with the difference for A
        int closestDiff = abs(digitSum(A) - goalDigitSum);  

        // Iterate through elements A -> B, checking for closest digit sum
        for (int i = A; i <= B; ++i) {
            int currentDigitSum = digitSum(i);
            int currentDiff = abs(currentDigitSum - goalDigitSum);

            // Update closest if a smaller difference is found, or if it's tied but i is smaller
            if (currentDiff < closestDiff || (currentDiff == closestDiff && i < closest)) {
                closest = i;
                closestDiff = currentDiff;
            }
        }

        return closest;
    }
};