#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class BridgeSort {
public:
    string sortedHand(string hand) {
        // Create a vector for each suit
        vector<string> clubs, diamonds, hearts, spades;

        // Map the card values to order
        unordered_map<char, int> valueOrder = {
            {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
            {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}
        };

        // Separate cards into the corresponding suit vectors
        for (int i = 0; i < hand.size(); i += 2) {
            string card = hand.substr(i, 2);
            char suit = card[0];

            if (suit == 'C') {
                clubs.push_back(card);
            } else if (suit == 'D') {
                diamonds.push_back(card);
            } else if (suit == 'H') {
                hearts.push_back(card);
            } else if (suit == 'S') {
                spades.push_back(card);
            }
        }

        // Sorting function for cards based on the mapped value order
        auto sortByValue = [&valueOrder](const string& a, const string& b) {
            return valueOrder[a[1]] < valueOrder[b[1]];
        };

        // Sort each suit vector
        sort(clubs.begin(), clubs.end(), sortByValue);
        sort(diamonds.begin(), diamonds.end(), sortByValue);
        sort(hearts.begin(), hearts.end(), sortByValue);
        sort(spades.begin(), spades.end(), sortByValue);

        // Join the sorted vectors in the correct order
        string sortedHand;
        for (const auto& card : clubs) sortedHand += card;
        for (const auto& card : diamonds) sortedHand += card;
        for (const auto& card : hearts) sortedHand += card;
        for (const auto& card : spades) sortedHand += card;

        return sortedHand;
    }
};
