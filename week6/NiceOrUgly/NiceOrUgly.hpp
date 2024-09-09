#include <iostream>
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
        bool guaranteedUgly = false;

        for (int i = 0; i < n; i++) {
            int vowelCountMin = 0, vowelCountMax = 0;
            int consonantCountMin = 0, consonantCountMax = 0;

            // Check a substring of up to 5 characters
            for (int j = i; j < n && j < i + 5; j++) {
                char c = s[j];

                if (c == '?') {
                    // '?' can be either vowel or consonant
                    vowelCountMax++;
                    consonantCountMax++;
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

                // If max possible count of consecutive vowels or consonants leads to being ugly
                if (vowelCountMax >= 3 || consonantCountMax >= 5) {
                    possibleUgly = true;
                }

                // If count makes it definitely ugly
                if (vowelCountMin >= 3 || consonantCountMin >= 5) {
                    return "UGLY";
                }
            }
        }

        // If no definite ugly case is found, but possible ugly exists due to '?'
        if (possibleUgly) {
            // Handle '?' ambiguity where it could lead to both UGLY and NICE outcomes
            bool canBeNice = false;
            bool canBeUgly = false;

            for (int i = 0; i < n; i++) {
                if (s[i] == '?') {
                    // Simulate both vowel and consonant replacements
                    string sVowel = s;
                    string sConsonant = s;

                    // Replace '?' with a vowel ('A') in one string and a consonant ('B') in the other
                    sVowel[i] = 'A';
                    sConsonant[i] = 'B';

                    if (describeHelper(sVowel) == "NICE") {
                        canBeNice = true;
                    }
                    if (describeHelper(sConsonant) == "UGLY") {
                        canBeUgly = true;
                    }

                    if (canBeUgly && canBeNice) {
                        return "42";  // Ambiguous, both outcomes are possible
                    }
                }
            }

            // If '?' always makes it ugly, return UGLY, else NICE
            return canBeUgly ? "UGLY" : "NICE";
        }

        // If none of the above, return NICE
        return "NICE";
    }

    // Helper function to avoid recursion and handle '?' locally
    string describeHelper(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int vowelCount = 0, consonantCount = 0;

            for (int j = i; j < n && j < i + 5; j++) {
                char c = s[j];
                if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    vowelCount++;
                    consonantCount = 0;
                } else {
                    consonantCount++;
                    vowelCount = 0;
                }

                if (vowelCount >= 3) return "UGLY";
                if (consonantCount >= 5) return "UGLY";
            }
        }
        return "NICE";
    }
};