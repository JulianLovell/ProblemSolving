// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// class CatGame {
//    public:
//     int getNumber(vector<int> coordinates, int X) {
//         int n = coordinates.size();
//         int minRange = INT_MAX;

//         // Try all combinations of moving each cat left or right
//         for (int mask = 0; mask < (1 << n); ++mask) {
//             int minPosition = INT_MAX;
//             int maxPosition = INT_MIN;

//             // For each cat, decide whether to move it left or right based on the bit in mask
//             for (int i = 0; i < n; ++i) {
//                 int newPos = (mask & (1 << i)) ? coordinates[i] + X : coordinates[i] - X;

//                 minPosition = min(minPosition, newPos);
//                 maxPosition = max(maxPosition, newPos);
//             }

//             // Calculate the range for this configuration and update the minimum range found
//             minRange = min(minRange, maxPosition - minPosition);
//         }

//         return minRange;
//     }
// };
