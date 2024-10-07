#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MatchNumbersEasy {
public:
    string maxNumber(vector<int> matches, int n) {
        // Find the minimum number of matches needed to form any digit
        int minMatch = *min_element(matches.begin(), matches.end());

        // Calculate the maximum number of digits that can be formed
        int numDigits = n / minMatch;
        if (numDigits == 0) return "0";

        // Check if only 0 can be formed
        bool onlyZero = true;
        for(int i = 1; i < matches.size(); ++i){
            if(matches[i] <= n){
                onlyZero = false;
                break;
            }
        }
        if(onlyZero){
            // If 0 can be formed, return 0
            return "0";
        }

        string result = "";
        for(int i = 0; i < numDigits; ++i){
            // Try to place the largest possible digit at the current position
            for(int d = matches.size()-1; d >=0; --d){
                // Not enough matches for this digit
                if(matches[d] > n) continue;

                // Check if the remaining matches can form the rest of the digits
                if(n - matches[d] >= (numDigits - i -1) * minMatch){
                    // Avoid leading zero if it's not the only digit
                    if(i == 0 && d == 0 && numDigits >1) continue;
                    
                    result += to_string(d);
                    n -= matches[d];
                    break;
                }
            }
        }
        return result;
    }
};
