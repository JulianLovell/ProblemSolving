#include <iostream>

using namespace std;

class RugSizes {
public:
    int rugCount(int area) {
        // Set up counter
        int count = 0;

        // Iterate through possible widths
        for (int width = 1; width * width <= area; width++) {
            if (area % width == 0) {
                int length = area / width;

                // Check for the both length and width being even
                if ((width != length && !(width % 2 == 0 && length % 2 == 0)) || (width == length)) {
                    count++;
                }
            }
        }

        return count;
    }
};