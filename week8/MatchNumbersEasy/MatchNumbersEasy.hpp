#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MatchNumbersEasy {
   public:
    string maxNumber(vector<int> matches, int n) {
        // Find the minimum number of matches needed to form any digit
        int minMatch = *min_element(matches.begin(), matches.end());

        // Calculate the maximum number of digits that can be formed
        int maxDigits = n / minMatch;

        // Iterate from maxDigits down to 1 to find the largest possible number
        for (int digitCount = maxDigits; digitCount >= 1; --digitCount) {
            string number = "";
            int remainingMatches = n;

            for (int i = 0; i < digitCount; ++i) {
                // Try to place the largest possible digit at this position
                bool digitPlaced = false;
                for (int d = matches.size() - 1; d >= 0; --d) {
                    int cost = matches[d];
                    // Check if there are enough matches left to place this digit
                    if (remainingMatches < cost) {
                        continue;
                    }

                    // Calculate the minimum matches needed for the remaining digits
                    int minNeeded = (digitCount - i - 1) * minMatch;
                    if (remainingMatches - cost < minNeeded) {
                        continue;
                    }

                    // Avoid placing 0 as the first digit if it's not the only digit
                    if (i == 0 && d == 0 && digitCount > 1) {
                        continue;
                    }

                    // Place the digit
                    number += to_string(d);
                    remainingMatches -= cost;
                    digitPlaced = true;
                    break;
                }

                if (!digitPlaced) {
                    // Couldn't place any digit at this position
                    number = "";
                    break;
                }
            }

            if (!number.empty()) {
                return number;
            }
        }

        // If no digits can be placed, return 0
        return "0";
    }
};
