#include <vector>
#include <string>
#include <climits>

using namespace std;

class MooingCows {
public:
    int dissatisfaction(vector<string>& farmland) {
        int n = farmland.size();
        int m = farmland[0].size();
        int minDissatisfaction = INT_MAX;
        
        // List to hold the positions of all cows
        vector<pair<int, int>> cowPositions;
        
        // Collect all cow positions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (farmland[i][j] == 'C') {
                    cowPositions.push_back({i, j});
                }
            }
        }
        
        // calculate total dissatisfaction if that cow moos, for each row
        for (auto& cow : cowPositions) {
            int totalDissatisfaction = 0;
            for (auto& otherCow : cowPositions) {
                if (cow != otherCow) {
                    int distSquared = (cow.first - otherCow.first) * (cow.first - otherCow.first)
                                    + (cow.second - otherCow.second) * (cow.second - otherCow.second);
                    totalDissatisfaction += distSquared;
                }
            }
            // Update minimum dissatisfaction
            if (totalDissatisfaction < minDissatisfaction) {
                minDissatisfaction = totalDissatisfaction;
            }
        }
        
        return minDissatisfaction;
    }
};
