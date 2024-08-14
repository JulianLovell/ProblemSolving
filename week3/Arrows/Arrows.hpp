#include <iostream>
#include <string>

using namespace std;

class Arrows {
public:
    int longestArrow(string s) {
        int longestFound = -1;

        // Iterate over the string to find left facing arrows
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '<') {
                // Start count with the '<'
                int length = 1;
                int temp = i + 1;

                // First check for a left double arrow "<="
                while (temp < s.length() && s[temp] == '=') {
                    length++;
                    temp++;
                }

                // If no '=' was found, check for left single arrow "<-"
                if (length == 1) {
                    temp = i + 1;
                    while (temp < s.length() && s[temp] == '-') {
                        length++;
                        temp++;
                    }
                }

                // Update the longest arrow found
                if (length > 0) {
                    longestFound = max(longestFound, length);
                }
            }
        }

        // Iterate over the string to find right facing arrows
        for (int i = 0; i < s.length(); i++) {
            int length = 0;
            int temp = i;

            // First check for a right double arrow "=>"
            while (temp < s.length() && s[temp] == '=') {
                length++;
                temp++;
            }

            // If no '=' was found, check for right single arrow "->"
            if (length == 0) {
                temp = i;
                while (temp < s.length() && s[temp] == '-') {
                    length++;
                    temp++;
                }
            }

            // If we find a '>', complete the arrow
            if (temp < s.length() && s[temp] == '>') {
                length++;
                longestFound = max(longestFound, length);
            }
        }

        return longestFound;
    }
};
