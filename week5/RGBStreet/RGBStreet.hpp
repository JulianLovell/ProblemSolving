#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

class RGBStreet {
public:
    int estimateCost(vector<string> houses) {
        // Number of houses
        int n = houses.size();
        // Cost matrix to store costs for Red, Green and Blue
        vector<vector<int>> cost(n, vector<int>(3));
        
        // Parse input strings to extract costs
        for (int i = 0; i < n; ++i) {
            stringstream ss(houses[i]);
            // Get costs for Red Green Blue
            ss >> cost[i][0] >> cost[i][1] >> cost[i][2];
        }
        
        // DP table to store minimum costs
        vector<vector<int>> dp(n, vector<int>(3));
        
        // Initialize the cost for the first house
        // Red
        dp[0][0] = cost[0][0];
        // Green
        dp[0][1] = cost[0][1];
        // Blue
        dp[0][2] = cost[0][2];
        
        // Fill the DP table
        for (int i = 1; i < n; ++i) {
            // Red
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
            // Green
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
            // Blue
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2]; 
        }
        
        // Return minimum cost for painting all houses
        return min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};