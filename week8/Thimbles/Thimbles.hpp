#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Thimbles {
public:
    int thimbleWithBall(vector<string> swaps) {
        // Ball location tracker, starting in the first cup (1)
        int ballLocation = 1;

        // Loop through the swaps vector
        for (int i = 0; i < swaps.size(); ++i) {
            // Read the current swap to make it easier in the next step
            string currentSwap = swaps[i];

            // Read in thimble X and thimble Y
            char thimbleX = currentSwap[0];
            char thimbleY = currentSwap[2];

            // Convert char to int values
            int intThimbleX = thimbleX - '0';
            int intThimbleY = thimbleY - '0';

            // Check if the ball is currently in either thimble
            if (intThimbleX == ballLocation) {
                // If the ball is in thimble X, swap it to Y
                ballLocation = intThimbleY;
            } else if (intThimbleY == ballLocation) {
                // If the ball is in thimble Y, swap it to X
                ballLocation = intThimbleX;
            }
        }

        // Return the final location of the ball
        return ballLocation;
    }
};
