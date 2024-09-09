#include <string>
using namespace std;

class NiceOrUgly {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string describe(string s) {
        int n = s.length();
        bool possibleUgly = false;

        for (int i = 0; i < n; i++) {
            int vowelCountMin = 0, vowelCountMax = 0;
            int consonantCountMin = 0, consonantCountMax = 0;

            // Check substring of up to 5 characters since max condition is 5 consonants
            for (int j = i; j < n && j < i + 5; j++) {
                char c = s[j];

                if (c == '?') {
                    // '?' can be both vowel and consonant
                    vowelCountMax++;
                    consonantCountMax++;
                    // Resetting the min counts since we don't know if it's a vowel or consonant
                    vowelCountMin = max(0, vowelCountMin - 1);
                    consonantCountMin = max(0, consonantCountMin - 1);
                } else if (isVowel(c)) {
                    // It's a definite vowel
                    vowelCountMax++;
                    vowelCountMin++;
                    consonantCountMax = 0;
                    consonantCountMin = 0;
                } else {
                    // It's a definite consonant
                    consonantCountMax++;
                    consonantCountMin++;
                    vowelCountMax = 0;
                    vowelCountMin = 0;
                }

                // Check if the max (possible) count makes it definitely ugly
                if (vowelCountMax >= 3 || consonantCountMax >= 5) {
                    return "UGLY";
                }

                // Check if the definite (min) count makes it definitely ugly
                if (vowelCountMin >= 3 || consonantCountMin >= 5) {
                    return "UGLY";
                }
            }
        }

        // If no definite ugly case is found, check if it's ambiguous
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                // If there are still question marks, it can be either NICE or UGLY
                return "42";
            }
        }

        // If it's neither ugly nor ambiguous, it must be NICE
        return "NICE";
    }
};
