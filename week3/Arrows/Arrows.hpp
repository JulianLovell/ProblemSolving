#include <iostream>
#include <string>

using namespace std;

class Arrows {
public:
    int longestArrow(string s) {
        // Set initial value to -1 so that if none are found then this is returned
        int longestFound = -1;

        // Iterate over the string to find potential arrows
        for (int i = 0; i < s.length(); i++) {
            int length = 1; // Start counting length from the first character

            // Check for left single arrow "<-"
            if (s[i] == '<') {
                int temp = i + 1;
                while (temp < s.length() && s[temp] == '-') {
                    length++;
                    temp++;
                }
                if (length > 1) {
                    longestFound = max(longestFound, length);
                }
            }

            // Reset length and then check for left double arrow "<="
            length = 1;
            if (s[i] == '<') {
                int temp = i + 1;
                while (temp < s.length() && s[temp] == '=') {
                    length++;
                    temp++;
                }
                if (length > 1) {
                    longestFound = max(longestFound, length);
                }
            }

            // Check for right single arrow "->"
            if (s[i] == '-') {
                // Length should start at 0 for "-" and "="
                length = 0;
                int temp = i;
                while (temp < s.length() && s[temp] == '-') {
                    length++;
                    temp++;
                }
                if (temp < s.length() && s[temp] == '>') {
                    // Then include the '>'
                    length++;
                    longestFound = max(longestFound, length);
                }
            }

            // Check for right double arrow "=>"
            if (s[i] == '=') {
                length = 0;
                int temp = i;
                while (temp < s.length() && s[temp] == '=') {
                    length++;
                    temp++;
                }
                if (temp < s.length() && s[temp] == '>') {
                    length++;
                    longestFound = max(longestFound, length);
                }
            }
        }

        return longestFound;
    }
};