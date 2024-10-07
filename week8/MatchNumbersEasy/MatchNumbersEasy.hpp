#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MatchNumbersEasy {
public:
    string maxNumber(vector<int> matches, int n) {
        string result = "";
        
        // Find the smallest number of matches needed for any digit
        int minMatches = *min_element(matches.begin(), matches.end());

        // If no digits can be formed return 0
        if (n < minMatches) return "0";

        // Calculate how many digits we can form with the available matches
        int numDigits = n / minMatches;
        // If no digits can be formed, return 0
        if (numDigits == 0) return "0";

        // Flag to avoid leading zeros
        bool leadingDigitSelected = false;

        // Now, try to maximize the value of the digits we can form
        for (int i = 0; i < numDigits; ++i) {
            // Find the largest possible digit we can use for this position
            for (int j = matches.size() - 1; j >= 0; --j) {
                int remainingMatches = n - matches[j];
                // Matches required for the remaining digits
                int remainingDigits = (numDigits - i - 1) * minMatches;

                // If we are selecting the first digit, avoid choosing 0 unless it's the only choice
                if (!leadingDigitSelected && j == 0 && numDigits > 1) {
                    // Skip the digit 0 for the first digit
                    continue;
                }

                if (remainingMatches >= remainingDigits) {
                    // If we can afford to use this digit and still have enough matches left
                    result += to_string(j);
                    // Subtract the used matches
                    n -= matches[j];
                    // Mark that we've selected the first digit
                    leadingDigitSelected = true;
                    break;
                }
            }
        }

        return result;
    }
};
