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

        // For each cat, calculate both possible positions (move left or right)
        for (int i = 0; i < coordinates.size(); ++i) {
            int left = coordinates[i] - X;
            int right = coordinates[i] + X;

            // Update the minimum and maximum possible positions
            minPos = min(minPos, min(left, right));
            maxPos = max(maxPos, max(left, right));
        }

        // Return the difference between the maximum and minimum positions
        return maxPos - minPos;
    }
};
