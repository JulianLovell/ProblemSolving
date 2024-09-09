#include <iostream>
#include <string>

using namespace std;

class NiceOrUgly {
public:
    string describe(string s) {
        int n = s.size();
        bool couldBeUgly = false, couldBeNice = false;

        // Check options for the '?' being either a vowel or a consonant
        for (int mode = 0; mode < 2; ++mode) {
            int vowels = 0, consonants = 0;
            bool definitelyUgly = false;

            for (int i = 0; i < n; ++i) {
                char ch = s[i];

                // Check for ?
                if (ch == '?') {
                    if (mode == 0) {
                        // Treat ? as a vowel
                        vowels++;
                        consonants = 0;
                    } else {
                        // Treat ? as a consonant
                        consonants++;
                        vowels = 0;
                    }
                } else if (isVowel(ch)) {
                    // Vowel found
                    vowels++;
                    consonants = 0;
                } else if (isConsonant(ch)) {
                    // Consonant found
                    consonants++;
                    vowels = 0;
                }

                // Check for the UGLY condition
                if (vowels == 3 || consonants == 5) {
                    definitelyUgly = true;
                    break;
                }
            }

            if (!definitelyUgly) {
                couldBeNice = true;
            } else {
                couldBeUgly = true;
            }
        }

        if (couldBeUgly && couldBeNice) {
            // Can be either ugly or nice
            return "42";
        } else if (couldBeUgly) {
            // Always ugly
            return "UGLY";
        } else {
            // Always nice
            return "NICE";
        }
    }

    // Function to check if a character is a vowel
    bool isVowel(char ch) {
        return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    // Function to check if a character is a consonant
    bool isConsonant(char ch) {
        // If it is not a vowel but must still be a letter
        return !isVowel(ch) && ch >= 'A' && ch <= 'Z';
    }
};