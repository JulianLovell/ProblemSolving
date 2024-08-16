#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MonstersValley2{
    public:
    int minimumPrice(vector<int> dread, vector<int> price){
        // Party starts with scariness of 0
        int cheapestParty = INT_MAX;
        // Dread values could cause overflow on int
        long long partyDread = 0;
        int totalCost = 0;

        // Loop through each moster
        for (int i = 0; i < dread.size(); ++i){
            // If encountered monster is scarier than current party, then we will always have to buy it
            if (dread[i] > partyDread){
                totalCost += price[i];
                partyDread += dread[i];
            }
            
            // Else we get the choice of buying it or walking past
            else {
                // Optional bribe
                int costIfBribed = totalCost + price[i];
                long long newPartyDread = partyDread + dread[i];

                // Compare costs of bribe vs skip
                if (price[i] == 1){
                    totalCost += price[i];
                    partyDread += dread[i];
                }
            }

            // Some sort of step to check if totalCost < cheapestParty and updating if needed

        }

        return totalCost;
    }
};