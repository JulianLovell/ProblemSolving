#include <string>

using namespace std;

class NiceOrUgly {
public:
    // Helper function from previous version
    bool isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string describe(string s) {
        int n = s.length();
        // Tracks if it can be ugly
        bool possibleUgly = false;
        // Tracks if it is definitely nice
        bool definitelyNice = true;

        for (int i = 0; i < n; i++) {
            int vowelCountMin = 0;
            int vowelCountMax = 0;
            int consonantCountMin = 0;
            int consonantCountMax = 0;

            // Go through substring of up to 5 characters since the max condition is 5 consonants
            for (int j = i; j < n && j < i + 5; j++) {
                char c = s[j];

                // '?' can be either vowel or consonant, so need to handle both possibilities
                if (c == '?') {
                    // It can be a vowel
                    vowelCountMax++;
                    // It can be a consonant
                    consonantCountMax++;
                    // If it is a consonant, then reset the min vowel count
                    vowelCountMin = max(0, vowelCountMin - 1);
                    // If it is a vowel, then reset the min consonant count
                    consonantCountMin = max(0, consonantCountMin - 1);
                } else if (isVowel(c)) {
                    // If it's a vowel, increase the vowel counters and reset consonant counters
                    vowelCountMax++;
                    vowelCountMin++;
                    consonantCountMax = 0;
                    consonantCountMin = 0;
                } else {
                    // If it's a consonant, increase the consonant counters and reset vowel counters
                    consonantCountMax++;
                    consonantCountMin++;
                    vowelCountMax = 0;
                    vowelCountMin = 0;
                }

                // If we reach 3 possible consecutive vowels or 5 possible consecutive consonants, it may be UGLY
                if (vowelCountMax >= 3 || consonantCountMax >= 5) {
                    // Check if replacing ? with both vowel and consonant still makes it ugly
                    bool uglyForBoth = vowelCountMax >= 3 && consonantCountMax >= 5;
                    // If both conditions are met, it's definitely ugly
                    if (uglyForBoth) return "UGLY";
                    possibleUgly = true;
                }

                // If we reach 3 definite consecutive vowels, it's definitely ugly
                if (vowelCountMin >= 3) return "UGLY";
                // If we reach 5 definite consecutive consonants, it's definitely ugly
                if (consonantCountMin >= 5) return "UGLY";
            }
        }

        // If it can be both UGLY and NICE, return "42"
        if (possibleUgly) {
            bool amb = false;

            for (int i = 0; i < n; i++) {
                if (s[i] == '?') {
                    amb = true;
                    break;
                }
            }

            // If there's no ambiguity, return "UGLY"
            if (!amb) return "UGLY";
            
            // If there is, return 42
            return "42";
        }

        // If none of the above, then it must be NICE
        return "NICE";
    }
};