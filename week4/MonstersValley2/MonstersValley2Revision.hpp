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

// Main function to run the test cases
int main() {
    MonstersValley2 mv2;

    // Test case 0
    vector<int> dread0 = {8, 5, 10};
    vector<int> price0 = {1, 1, 2};
    cout << "Test case 0: " << mv2.minimumPrice(dread0, price0) << " (Expected: 2)" << endl;

    // Test case 1
    vector<int> dread2 = {200, 107, 105, 206, 307, 400};
    vector<int> price2 = {1, 2, 1, 1, 1, 2};
    cout << "Test case 2: " << mv2.minimumPrice(dread2, price2) << " (Expected: 2)" << endl;

    // Test case 2
    vector<int> dread3 = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333};
    vector<int> price3 = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1};
    cout << "Test case 3: " << mv2.minimumPrice(dread3, price3) << " (Expected: 5)" << endl;

    return 0;
}