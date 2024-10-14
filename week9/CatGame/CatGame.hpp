
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class CatGame {
public:
    int getNumber(vector<int> coordinates, int X) {
        // Sort the coordinates
        sort(coordinates.begin(), coordinates.end());

        // Initialise min and max
        int minPos = INT_MAX;
        int maxPos = INT_MIN;

        // Iterate through all the coordinates and adjust the positions
        for (int i = 0; i < coordinates.size(); ++i) {
            int current = coordinates[i];
            // Position if moved left
            int moveLeft = current - X;
            // Position if moved right
            int moveRight = current + X;

            // Check if the current position is smaller than minPos
            if (current < minPos) {
                // Move it right to reduce the gap
                coordinates[i] = moveRight;
            }
            // Check if the current position is larger than maxPos
            else if (current > maxPos) {
                // Move it left to reduce the gap
                coordinates[i] = moveLeft;
            }
            // If current position is within the ranges
            else {
                // Check which is further away
                if (current - minPos > maxPos - current) {
                    // Move towards minPos
                    coordinates[i] = moveLeft;
                } else {
                    // Move towards maxPos
                    coordinates[i] = moveRight;
                }
            }

            // Update min and max based on the new position
            minPos = min(minPos, coordinates[i]);
            maxPos = max(maxPos, coordinates[i]);
        }

        // Return the final difference between max and min positions
        return maxPos - minPos;
    }
};
