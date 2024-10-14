#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class CatGame{
    public:
    int getNumber(vector<int> coordinates, int X){
        // Initialise the min and max possible positions
        int minPosition = INT_MAX;
        int maxPosition = INT_MIN;

        // Iterate over all cats to find max/min positions
        for (int i = 0; i < coordinates.size(); ++i){
            //For each cat, calculate both possible positions
            int leftPos = coordinates[i] - X;
            int rightPos = coordinates[i] + X;

            // Update gloabal min and max positions
            minPosition = min(minPosition, min(leftPos, rightPos));
            maxPosition = max(maxPosition, max(leftPos, rightPos))
        }

        // Return the smallest possible difference between the max and min positions
        return maxPosition - minPosition;
    }
};