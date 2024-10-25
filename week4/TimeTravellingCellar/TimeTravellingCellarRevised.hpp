#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TimeTravellingCellar {
   public:
    int determineProfit(vector<int> profit, vector<int> decay) {
        // Find the maximum profit value and minimum decay value
        int maxProfitValue = *max_element(profit.begin(), profit.end());
        int minDecayValue = *min_element(decay.begin(), decay.end());

        // Calculate the best possible profit by subtracting the minimum decay from the maximum profit
        int maxProfit = maxProfitValue - minDecayValue;

        return maxProfit;
    }
};
