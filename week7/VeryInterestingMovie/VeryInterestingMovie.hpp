#include <iostream>
#include <vector>
#include <string>

using namespace std;

class VeryInterestingMovie {
public:
    int maximumPupils(vector<string> seats) {
        int maxPupils = 0;

        // Get number of rows and seats per row for readability
        int seatRows = seats.size();
        int seatsPerRow = seats[0].size();

        // Loop through each row
        for (int i = 0; i < seatRows; ++i) {
            // Loop through each seat in the current row
            for (int j = 0; j < seatsPerRow; ++j) {
                // If the seat is available Y
                if (seats[i][j] == 'Y') {
                    // Place a student in this seat
                    ++maxPupils;

                    // Skip the next seat to avoid adjacent placement
                    j++;
                }
            }
        }

        return maxPupils;
    }
};