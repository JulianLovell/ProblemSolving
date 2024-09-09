#include <iostream>
#include <string>

using namespace std;

class BlackAndWhiteSolitaire {
public:
    int minimumTurns(string cardFront) {
        int size = cardFront.size();
        
        // Case 1: Starting with B
        int flipsPattern1 = 0;
        // Start with B
        char expected = 'B';
        
        for (int i = 0; i < size; ++i) {
            // Check if the current card is in the wrong spot for this pattern
            if (cardFront[i] != expected) {
                flipsPattern1++;
            }
            // Flip expected value for the next position
            if (expected == 'B') {
                expected = 'W';
            } else {
                expected = 'B';
            }
        }

        // Case 2: Starting with W
        int flipsPattern2 = 0;
        // Start with W
        expected = 'W';
        
        for (int i = 0; i < size; ++i) {
            // Check if the current card is in the wrong spot for this pattern
            if (cardFront[i] != expected) {
                flipsPattern2++;
            }
            // Flip expected value for the next position
            if (expected == 'W') {
                expected = 'B';
            } else {
                expected = 'W';
            }
        }

        // Return the minimum number of flips required
        return min(flipsPattern1, flipsPattern2);
    }
};