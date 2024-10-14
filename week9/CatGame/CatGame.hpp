#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class CatGame {
   public:
    int getNumber(vector<int> coordinates, int X) {
        // Sort the coordinates
        sort(coordinates.begin(), coordinates.end());

        // Initialize min and max cats to the first and last position
        int minCat = coordinates[0];
        int maxCat = coordinates.back();

        // Iterate over all cats
        for (int i = 1; i < coordinates.size(); ++i) {
            // Calculate the possible new positions for the current cat
            int leftMove = coordinates[i] - X;
            int rightMove = coordinates[i] + X;

            // Move the cat in a way that keeps the range between minCat and maxCat smallest
            if (leftMove > maxCat || rightMove < minCat) {
                // If the left move extends the range, move the cat to the right
                if (rightMove < minCat) {
                    coordinates[i] = rightMove;
                } else {
                    coordinates[i] = leftMove;
                }
            } else {
                // If the cat can be moved inside the minCat/maxCat range, choose the direction
                if (abs(leftMove - minCat) < abs(rightMove - maxCat)) {
                    coordinates[i] = leftMove;
                } else {
                    coordinates[i] = rightMove;
                }
            }

            // Recalculate minCat and maxCat after the move
            minCat = min(minCat, coordinates[i]);
            maxCat = max(maxCat, coordinates[i]);
        }

        // Return the smallest possible difference between max and min positions
        return maxCat - minCat;
    }
};