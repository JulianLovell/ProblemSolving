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
        // Trakcks if it can be ugly
        bool possibleUgly = false;
        // Tracks if it is definetly nice
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
                if (vowelCountMax >= 3 || consonantCountMax >= 5) possibleUgly = true;

                // If we reach 3 definite consecutive vowels, its definitely ugly
                if (vowelCountMin >= 3) return "UGLY";
                // If we reach 5 definite consecutive consonants, its definitely ugly
                if (consonantCountMin >= 5) return "UGLY";
            }
        }

        // If it can be both UGLY and NICE, return "42"
        if (possibleUgly) {
            return "42";
        }

        // If none of the above, then it must be NICE
        return "NICE";
    }
};
