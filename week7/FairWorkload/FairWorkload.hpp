#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class FairWorkload {
public:
    // Helper to check if we can partition the cabinets with maxWork as the upper limit
    bool canDistribute(const vector<int>& folders, int workers, int maxWork) {
        // Initialising
        int currentSum = 0;
        int requiredWorkers = 1;

        for (int i = 0; i < folders.size(); ++i) {
            if (currentSum + folders[i] > maxWork) {
                // If adding the current folder exceeds maxWork, assign to a new worker
                requiredWorkers++;
                // New worker starts with this folder
                currentSum = folders[i];
                if (requiredWorkers > workers) {
                    // More workers needed than available
                    return false;
                }
            } else {
                currentSum += folders[i];
            }
        }
        // Return true as partitioning is possible with maxWork
        return true; 
    }

    // Function to find the minimum possible maximum workload for workers
    int getMostWork(vector<int> folders, int workers) {
        // Min possible max work
        int low = *max_element(folders.begin(), folders.end());
        // Max possible work
        int high = accumulate(folders.begin(), folders.end(), 0);

        // Binary search for the minimum maximum workload
        while (low < high) {
            int mid = (low + high) / 2;
            if (canDistribute(folders, workers, mid)) {
                // Try to minimuse that max work
                high = mid;
            } else {
                // Increase workload
                low = mid + 1;
            }
        }

        // This will return as the minimum possible, max work
        return low;
    }
};
