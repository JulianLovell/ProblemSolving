#include <iostream>
#include <string>

using namespace std;

class Arrows {
public:
    int longestArrow(string s) {
        int longestFound = -1;

        // Iterate over the string to find potential arrows
        for (int i = 0; i < s.length(); i++) {
            // Start counting length from the first character
            int length = 1;

            // Check for left single arrow "<-" or "<="
            if (s[i] == '<') {
                int temp = i + 1;
                while (temp < s.length() && (s[temp] == '-' || s[temp] == '=')) {
                    length++;
                    temp++;
                }
                longestFound = max(longestFound, length);
            }

            // Check for right single arrow "->" or "=>"
            if (s[i] == '-' || s[i] == '=') {
                length = 0;
                int temp = i;
                while (temp < s.length() && (s[temp] == '-' || s[temp] == '=')) {
                    length++;
                    temp++;
                }
                if (temp < s.length() && s[temp] == '>') {
                    // Include arrow head
                    length++;
                    longestFound = max(longestFound, length);
                }
            }

            // Check for just ">" or "<"
            if (s[i] == '<' || s[i] == '>') {
                longestFound = max(longestFound, 1);
            }
        }

        return longestFound;
    }
};