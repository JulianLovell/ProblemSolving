#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MonstersValley2 {
public:
    int minimumPrice(vector<int> dread, vector<int> price) {
        int n = dread.size();  // Number of monsters
        
        // Create a 2D vector to store the minimum cost for reaching a certain amount of scariness
        // Max scariness possible to achieve
        int maxScariness = 2 * n;
        vector<vector<long long>> dreadPrice(n + 1, vector<long long>(maxScariness + 1, LLONG_MAX));
        
        // Start with no monsters bribed, no scariness, and 0 cost
        dreadPrice[0][0] = 0;

        // Loop over each monster
        for (int i = 0; i < n; ++i) {
            for (int s = 0; s <= maxScariness; ++s) {
                // If the current state is reachable
                if (dreadPrice[i][s] != LLONG_MAX) {
                    // Option 1: Bribe the current monster, increasing scariness and cost
                    if (s + dread[i] <= maxScariness) {
                        dreadPrice[i + 1][s + dread[i]] = min(dreadPrice[i + 1][s + dread[i]], dreadPrice[i][s] + price[i]);
                    }
                    
                    // Option 2: Skip the current monster, only if current scariness is enough to skip
                    if (s >= dread[i]) {
                        dreadPrice[i + 1][s] = min(dreadPrice[i + 1][s], dreadPrice[i][s]);
                    }
                }
            }
        }

        // Find the minimum cost to pass all monsters
        long long result = LLONG_MAX;
        for (int s = 0; s <= maxScariness; ++s) {
            result = min(result, dreadPrice[n][s]);
        }

        return (int)result;
    }
};