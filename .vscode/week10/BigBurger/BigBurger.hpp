#include <iostream>
#include <vector>

using namespace std;

class bigBurger{
    public:
    int maxWait(vector<int> arrival, vector<int> service){
        int longestWait = 0;
        int nextEarliestServe = 0;

        // update arrival vector to have calue as the previous customer + their service time
        for (int i = 1; i < arrival.size(); ++i){
            // earliest time next customer can be served
            int prevCustomerTime = (arrival[i - 1] + service[i - 1]);

            // if there is a customer already waiting
            if (arrival[i] < prevCustomerTime){
                // increase total wait by amount of time
                int currentWait = prevCustomerTime - arrival[i];

                // compare to current longestWait
                if (currentWait > longestWait){
                    longestWait = currentWait;
                }

                // update arrival time to represent their actual service time
                arrival[i] = prevCustomerTime;
            }
        }

        // return
        return longestWait;
    }
};