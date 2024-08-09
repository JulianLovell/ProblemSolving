#include <iostream>
#include <string>

using namespace std;

class Reppity {
public:
    int longestRep(string input) {
        int n = input.length();

        // Start with the longest possible substring length and go down to 1
        for (int len = n / 2; len > 0; len--) {
            // Try every starting position for substrings of this length
            for (int i = 0; i + len * 2 <= n; i++) {
                // Take substring of current length
                string sub = input.substr(i, len);

                // Check for another occurrence of this substring that does not overlap
                for (int j = i + len; j + len <= n; j++) {
                    if (input.substr(j, len) == sub) {
                        // Return length if found as this will be the largest possible
                        return len; 
                    }
                }
            }
        }

        // Return 0 if none
        return 0; 
    }
};
