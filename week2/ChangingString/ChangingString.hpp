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
        vector<int> differences(n);

        // Calculate initial differences
        for (int i = 0; i < n; i++) {
            differences[i] = abs(A[i] - B[i]);
        }

        // Sort differences in descending order
        sort(differences.begin(), differences.end(), greater<int>());

        // Minimize the largest differences by making changes
        for (int i = 0; i < K; i++) {
            // If the difference is already zero, we should increase it to maximize distance reduction
            if (differences[i] == 0) {
                // change a character in A to a character that maximises the diff
                differences[i] = 1;
            } else {
                // minimising the distance by matching character exactlky
                differences[i] = 0;
            }
        }

        // Sum up the total distance after the changes
        int totalDistance = 0;
        for (int i = 0; i < n; i++) {
            totalDistance += differences[i];
        }

        return totalDistance;
    }
};


