#include <climits>
#include <iostream>

using namespace std;

class TimeTravellingCellar {
   public:
    int determineProfit(int profit[], int decay[], int n) {
        // Set up best profit variable
        int bestProfit = 0;

        // For loop using i for proft array and j for decay array
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Ensure i and j cannot be equal as that would mean same cellar
                if (i != j) {
                    // Calc the profit of this combination
                    int currentProfit = profit[i] - decay[j];

                    // Update if bigger possible profit
                    if (currentProfit > bestProfit) {
                        bestProfit = currentProfit;
                    }
                }
            }
        }

        return bestProfit;
    }
};