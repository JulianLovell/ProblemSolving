#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PrefixFreeSets {
public:
    // Helper function to check if 'prefix' is a prefix of 'word'
    bool isPrefix(const string& prefix, const string& word) {
        if (prefix.size() > word.size()) {
            // We know it can't be a prefix if it's longer
            return false;
        }

        // Compare each character of prefix with word
        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] != word[i]) {
                // Does not match, not a prefix
                return false;
            }
        }

        // No mismatches, is a prefix
        return true;
    }

    // Main function
    int maxElements(vector<string> words) {
        // Get number of words
        int n = words.size();
        // Tracking whether a wrod should be included in the prefix-free set
        vector<bool> included(n, true);

        // Compare each word with every other word
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Skip same word
                if (i != j) {
                    // If word[j] is a prefix of word[i], exclude word[i]
                    if (isPrefix(words[j], words[i])) {
                        // Mark word as excluded
                        included[i] = false;
                        // Don't need further checks for this word now
                        break;
                    }
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

        // Return size of largest prefix-free subset
        return count;
    }
};