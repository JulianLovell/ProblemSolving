#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Barbecue {
   public:
    int eliminate(int n, vector<int> voter, vector<int> excluded) {

        // Count votes recieved by each person
        vector<int> votesAgainst(n, 0);
        // Count how many times each person voted
        vector<int> votesCast(n, 0);

        // Count votes against and votes cast
        for (int i = 0; i < voter.size(); ++i) {
            // Increase the count for the excluded person
            votesAgainst[excluded[i]]++;

            // Increase the count for the voter
            votesCast[voter[i]]++;
        }

        // Find the person with the maximum votes against
        int maxVotes = 0;

        // List of candidates with the highest votes
        vector<int> candidates;

        for (int i = 0; i < n; ++i) {
            if (votesAgainst[i] > maxVotes) {
                maxVotes = votesAgainst[i];

                // Clear the previous candidates
                candidates.clear();
                candidates.push_back(i);
            } else if (votesAgainst[i] == maxVotes) {
                // Add the person to candidates if they have the same votes
                candidates.push_back(i);
            }
        }

        // If there's only one candidate, return them
        if (candidates.size() == 1) {
            return candidates[0];
        }

        // If there's a tie, break it by finding who voted the most
        int maxVotesCast = 0;
        vector<int> finalCandidates;

        for (int i = 0; i < candidates.size(); ++i) {
            int candidate = candidates[i];
            if (votesCast[candidate] > maxVotesCast) {
                maxVotesCast = votesCast[candidate];
                
                // Clear previous candidates
                finalCandidates.clear();
                finalCandidates.push_back(candidate);
            } else if (votesCast[candidate] == maxVotesCast) {
                // Add the person to candidates if they have the same votes
                finalCandidates.push_back(candidate);
            }
        }

        // If there's still a tie, return the person with the smallest index
        return *min_element(finalCandidates.begin(), finalCandidates.end());
    }
};