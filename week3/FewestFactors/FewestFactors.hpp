#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class FewestFactors {
public:
    int number(vector<int> digits) {
        // Tracking min number of factors
        int fewestFactors = INT_MAX;
        // Tracking best number found so far (fewest factors + lowest)
        int resultNumber = INT_MAX; 

        // Sort the digits to generate possible numbers
        sort(digits.begin(), digits.end());

        do {
            // Form number from the current
            int num = 0;
            for (int digit : digits) {
                num = num * 10 + digit;
            }

            // Count number of factors for the number
            int factorCount = 0;
            for (int i = 1; i <= sqrt(num); ++i) {
                if (num % i == 0) {
                    // Count i and num/i as factors
                    factorCount += 2;  
                    // Correct double counting a number if num is a perfect square
                    if (i == num / i) factorCount--; 
                }
            }

            // Update if we find a number with fewer factors, or same number of factors but smaller
            if (factorCount < fewestFactors || (factorCount == fewestFactors && num < resultNumber)) {
                fewestFactors = factorCount;
                resultNumber = num;
            }

        } while (next_permutation(digits.begin(), digits.end()));

        // Return number with the fewest factors
        return resultNumber;
    }
};