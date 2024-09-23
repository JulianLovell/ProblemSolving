#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // For sorting

using namespace std;

class PrefixFreeSets {
public:
    // Helper function to check if 'prefix' is a prefix of 'word'
    bool isPrefix(const string& prefix, const string& word) {
        if (prefix.size() > word.size()) {
            // Can't be a prefix if it's longer
            return false;
        }

        // Compare each character of prefix with word
        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] != word[i]) {
                // Prefix doesn't match, not a prefix
                return false;
            }
        }

        // No mismatches, it is a prefix
        return true;
    }

    // Main function to find the largest prefix-free subset
    int maxElements(vector<string> words) {
        // Get total number of words
        int n = words.size();
        
        // Sort the words by length so we compare shorter words with longer ones
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        // Vector to track if the word should be included
        vector<bool> included(n, true);

        // Compare each word with longer words only
        for (int i = 0; i < n; i++) {
            if (!included[i]) continue;  // Skip if already excluded
            for (int j = i + 1; j < n; j++) {
                // If word[i] is a prefix of word[j], exclude word[i]
                if (isPrefix(words[i], words[j])) {
                    // Mark as excluded
                    included[i] = false;
                    // No further checks
                    break;
                }
            }
        }

        // Count how many words are still included in the prefix-free set
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (included[i]) {
                count++;
            }
        }

        // Return the size of the largest prefix-free subset
        return count;
    }
};
