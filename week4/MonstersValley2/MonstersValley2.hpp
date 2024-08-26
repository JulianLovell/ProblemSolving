#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MonstersValley2 {
public:
    int minimumPrice(vector<int> dread, vector<int> price) {
        // Number of monsters
        int n = dread.size();
        // Start from the first monster
        return monstersMethod(dread, price, 0, 0, 0, n);
    }

    // Method to explore all possible combinations
    int monstersMethod(const vector<int>& dread, const vector<int>& price, int index, long long partyDread, int totalCost, int n) {
        // If we have passed all monsters, return the total cost
        if (index == n) {
            return totalCost;
        }

        int minCost = INT_MAX;

        // Option 1: Bribe the current monster
        int bribeCost = totalCost + price[index];
        long long newPartyDread = partyDread + dread[index];
        minCost = min(minCost, monstersMethod(dread, price, index + 1, newPartyDread, bribeCost, n));

        // Option 2: Skip the current monster, but only if it's safe to do so
        if (partyDread >= dread[index]) {
            minCost = min(minCost, monstersMethod(dread, price, index + 1, partyDread, totalCost, n));
        }

        return minCost;
    }
};