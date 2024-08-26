// #include <climits>
// #include <iostream>
// #include <vector>

// using namespace std;

// class MonstersValley2 {
//    public:
//     int minimumPrice(vector<int> dread, vector<int> price) {
//         // Set up n to be dread.size() to make code later easier to write
//         int n = dread.size();

//         // Set up 2D vector for dynamic solving
//         int rows = n + 1;
//         int columns = 2 * n + 1;
//         vector<long long> initialRow(columns, LLONG_MAX);
//         // Initialize the 2D vector with rows number of initialRow
//         vector<vector<long long>> dreadPrice(rows, initialRow);

//         // Starting state: 0 monsters, 0 scariness and 0 cost
//         dreadPrice[0][0] = 0;

//         // Loop over each monster
//         for (int i = 0; i < n; ++i) {
//             // Loop over all scariness values
//             for (int s = 0; s <= 2 * n; ++s) {
//                 if (dreadPrice[i][s] != LLONG_MAX) {
//                     // Option 1: Bribe the monster
//                     dreadPrice[i + 1][s + dread[i]] = min(dreadPrice[i + 1][s + dread[i]], dreadPrice[i][s] + price[i]);

//                     // Option 2: Skip the monster as long as current scariness is high enough
//                     if (s >= dread[i]) {
//                         dreadPrice[i + 1][s] = min(dreadPrice[i + 1][s], dreadPrice[i][s]);
//                     }
//                 }
//             }
//         }

//         // Find the minimum cost to pass all monsters
//         long long result = LLONG_MAX;
//         for (int s = 0; s <= 2 * n; ++s) {
//             result = min(result, dreadPrice[n][s]);
//         }

//         return (int)result;
//     }
// };