#include <iostream>
#include <string>

using namespace std;

class RunLengthEncoding {
public:
    string decode(string text) {
        // Initialise new empty string
        string newString = "";

        int n = text.size();
        int i = 0;

        while (i < n) {
            int multi = 0;

            // Accumulate multi-digit numbers
            while (i < n && isdigit(text[i])) {
                // Convert char to int and accumulate
                multi = multi * 10 + (text[i] - '0');  
                ++i;
            }

            // If no number is found before a letter, assume a single occurrence
            if (multi == 0) {
                multi = 1;
            }

            // Append the character 'multi' times
            if (i < n && isalpha(text[i])) {
                for (int j = 0; j < multi; ++j) {
                    newString.push_back(text[i]);

                    // Check if the length exceeds 50 characters
                    if (newString.size() > 50) {
                        return "TOO LONG";
                    }
                }
            }

            // Move to next character
            ++i;
        }

        return newString;
    }
};