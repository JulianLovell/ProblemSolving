// PROCESS
// Calcualte initial distances by converting to ASCII values
// Sort these differences
// Change A characters
// Get new distance and return

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class ChangingString {
    public:

    int distance(string A, string B, int K) {
        int n = A.size();
        int totalDistance = 0;

        vector<int> differences(n);

        // Calc initial distances
        for (int i = 0; i < n; i++) {
            differences[i] = abs(A[i] - B[i]);
        }

        // pair differences with the corresponding indices
        vector<pair<int, int>> diffIndex;
        for (int i = 0; i < n; i++) {
            diffIndex.push_back({differences[i], i});
        }

        // Sort differences pairs descending
        sort(diffIndex.begin(), diffIndex.end(), greater<pair<int, int>>());

        // make K changes to minimise
        for (int i = 0; i < K; i++) {
            int idx = diffIndex[i].second;
            differences[idx] = 0;
        }

        // Sum up the remaining differences
        for (int i = 0; i < n; i++) {
            totalDistance += differences[i];
        }

        return totalDistance;
    }
};

