#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class CatGame {
public:
    int getNumber(vector<int> coordinates, int X) {
        int minPos = INT_MAX;
        int maxPos = INT_MIN;

        // For each cat, consider both possible positions (move left or right)
        for (int i = 0; i < coordinates.size(); ++i) {
            int left = coordinates[i] - X;
            int right = coordinates[i] + X;

            // Update the minimum position with the smallest possible value
            minPos = min(minPos, left);
            minPos = min(minPos, right);

            // Update the maximum position with the largest possible value
            maxPos = max(maxPos, left);
            maxPos = max(maxPos, right);
        }

        // Return the smallest possible difference between the rightmost and leftmost positions
        return maxPos - minPos;
    }
};