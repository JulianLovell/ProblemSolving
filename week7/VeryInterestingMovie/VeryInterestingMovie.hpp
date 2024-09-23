#include <iostream>
#include <string>

using namespace std; 

class VeryInterestingMovie{
    public:

    int maximumPupils(string[] seats){
        int maxPupils = 0;

        //set up max values of seats and seats i for readability, assuming same number of seats in every row
        int seatRows = seats.size();
        int seatsPerRow = seats[0].size();

        // nested loop to search through elements j of each element i within seats
        // Rows of seats
        for (int i = 0; i < seatRows; ++i){
            // code
            // Seats within each row
            for (int j = 0; j < seatsPerRow; ++j){
                //code
                // if seats[i[j]] == Y, seat is available, sit pupil
                if (seats[i[j]] == 'Y'){
                    ++maxPupils;
                }
            }
        }
    }
};