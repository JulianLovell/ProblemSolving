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

        // Sort differences descending
        sort(differences.begin(), differences.end(), greater<int>());
        

        // Reduce the largest K differences to 0
        for (int i = 0; i < K; i++) {
            if (differences[i] > 0) {
                differences[i] = 0;
            }
        }

        // Sum up the remaining differences
        for (int i = 0; i < n; i++) {
            totalDistance += differences[i];
        }

        return totalDistance;
    }
};

