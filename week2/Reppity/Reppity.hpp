#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Reppity {
public:
    int longestRep(string input) {
        int n = input.length();
        
        // Check substrings from the longest to the shortest
        for (int len = n / 2; len > 0; len--) {
            unordered_set<string> seenSubstrings;
            
            for (int i = 0; i + len <= n; i++) {
                string sub = input.substr(i, len);
                
                // If already found this substring, check if it appears again non-overlapping
                if (seenSubstrings.find(sub) != seenSubstrings.end()) {
                    // Found a repeating substring with length len
                    return len;
                }
                
                seenSubstrings.insert(sub);
            }
        }
        
        // If no repeating substring is found
        return 0;
    }
};