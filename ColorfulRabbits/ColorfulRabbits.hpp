#include <iostream>
#include <unordered_map>
#include <cmath>
#include <vector>

using namespace std;

class ColorfulRabbits {
public:
    int getMinimum(vector<int> replies) {
        // Set up map
        unordered_map<int, int> countMap;

        // Set up return var
        int totalRabbits = 0;
        
        // Count the number of times each reply is given
        for (int i = 0; i < replies.size(); ++i) {
            countMap[replies[i]]++;
        }
        
        // For each unique reply, calc the minimum number of rabbits
        for (unordered_map<int, int>::iterator i = countMap.begin(); i != countMap.end(); ++i) {
            int reply = i -> first;
            int count = i -> second;
            
            // Group rabbits into groups of (reply + 1)
            int groupSize = reply + 1;
            
            // Calculate how many groups we need and add the total rabbits
            // Use ceil function to round up
            int groups = ceil((double)count / groupSize);
            totalRabbits += (groups * groupSize);
        }
        
        return totalRabbits;
    }
};
