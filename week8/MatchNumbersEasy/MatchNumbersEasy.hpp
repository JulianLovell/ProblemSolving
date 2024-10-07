#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MatchNumbersEasy {
public:
    string maxNumber(vector<int> matches, int n) {
        string result = "";
        
        // Get the smallest matches value to ensure loop condition works properly
        int minMatches = *min_element(matches.begin(), matches.end());

        // While loop to continue until we run out of matches
        while (n >= minMatches) {
            // Iterate backwards through the matches to prioritize larger digits
            for (int i = matches.size() - 1; i >= 0; --i) {
                // Check if we have enough matches for the current digit
                if (n >= matches[i]) {
                    // Append the current digit to the result
                    result += to_string(i);
                    // Subtract the number of matches used for this digit
                    n -= matches[i];
                    // Break to start checking from the largest digit again
                    break;
                }
            }
        }
        
        // If no number formed, return 0
        return result.empty() ? "0" : result;
    }
};
