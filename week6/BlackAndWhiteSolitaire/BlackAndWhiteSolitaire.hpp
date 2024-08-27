#include <iostream>

using namespace std;

class BlackAndWhiteSolitiare {
    public:

    int minimumTurns(string cardFront){
        // Initialise size for readabilitiy and flips to track number of flipped cards
        int size = cardFront.size();
        int flips = 0;

        // Initialise starting card
        char prevCard = cardFront[0];

        // For loop to do whole process
        for (int i = 1; i < size; ++i){
            // Set current card
            char currentCard = cardFront[i];

            // Compare current to previous, if they don't follow pattern then correct and add to counter
            if (currentCard == prevCard){
                if (currentCard == 'B'){
                    currentCard = 'W';
                } else {
                    currentCard = 'B';
                }

                ++flips;
            }
        }

        return flips;
    }
};