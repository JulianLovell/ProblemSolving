#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class DifferentStrings {
public:
    int minimize(string A, string B) {
        // Maximum possible differences is the length of A
        int minDifference = A.size();

        // Slide A over all possible substrings of B of length equal to A
        for (int i = 0; i <= B.size() - A.size(); ++i) {
            int currentDifference = 0;

            // Compare A with the substring of B starting at position i
            for (int j = 0; j < A.size(); ++j) {
                if (A[j] != B[i + j]) {
                    ++currentDifference;
                }
            }
            
            // Update the minimum difference found
            minDifference = min(minDifference, currentDifference);
        }

        return minDifference;
    }
};
