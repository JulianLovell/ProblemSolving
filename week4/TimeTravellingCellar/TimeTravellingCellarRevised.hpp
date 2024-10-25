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

// Main function to run the test cases
int main() {
    TimeTravellingCellar ttc;

    // Test case 0
    vector<int> profit0 = {1, 2, 3};
    vector<int> decay0 = {3, 1, 2};
    cout << "Test case 0: " << ttc.determineProfit(profit0, decay0) << " (Expected: 2)" << endl;

    // Test case 1
    vector<int> profit1 = {3, 2};
    vector<int> decay1 = {1, 2};
    cout << "Test case 1: " << ttc.determineProfit(profit1, decay1) << " (Expected: 1)" << endl;

    // Test case 2
    vector<int> profit2 = {3, 3, 3};
    vector<int> decay2 = {1, 1, 1};
    cout << "Test case 2: " << ttc.determineProfit(profit2, decay2) << " (Expected: 2)" << endl;

    // Test case 3
    vector<int> profit3 = {1000, 500, 250, 125};
    vector<int> decay3 = {64, 32, 16, 8};
    cout << "Test case 3: " << ttc.determineProfit(profit3, decay3) << " (Expected: 992)" << endl;

    return 0;
}