#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MonstersValley2 {
public:
    int minimumPrice(vector<int> dread, vector<int> price) {
        int numMonsters = dread.size();
        long long maxDread = 0;

        for (int d : dread) {
            maxDread += d;
        }

        vector<vector<int>> dp(numMonsters + 1, vector<int>(maxDread + 1, INT_MAX));
        dp[0][0] = 0;

        for (int i = 0; i < numMonsters; ++i) {
            for (int j = 0; j <= maxDread; ++j) {
                if (dp[i][j] == INT_MAX) continue;

                // Option 1: Bribe the current monster
                long long newDread = j + dread[i];
                dp[i + 1][newDread] = min(dp[i + 1][newDread], dp[i][j] + price[i]);

                // Option 2: Skip the current monster if possible
                if (j >= dread[i]) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                }
            }
        }

        int minCost = INT_MAX;
        for (int j = 0; j <= maxDread; ++j) {
            minCost = min(minCost, dp[numMonsters][j]);
        }

        return minCost;
    }
};
