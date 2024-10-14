#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class ErdosNumber {
   public:
    vector<string> calculateNumbers(vector<string> publications) {
        // Adjacency list to represent the co-authorship graph
        unordered_map<string, unordered_set<string>> graph;
        // To store the Erdos number for each author
        unordered_map<string, int> erdosNumber;
        // Set of all authors
        unordered_set<string> authors;

        // Build the graph from the publications
        for (string pub : publications) {
            vector<string> authorsInPub = split(pub);
            for (string author : authorsInPub) {
                // Collect all authors
                authors.insert(author);
                for (string coAuthor : authorsInPub) {
                    if (author != coAuthor) {
                        // Create an undirected edge between all co-authors
                        graph[author].insert(coAuthor);
                    }
                }
            }
        }

        // BFS to calculate Erdos numbers
        queue<string> q;
        if (authors.count("ERDOS")) {
            q.push("ERDOS");
            // Paul Erdos has Erdos number 0
            erdosNumber["ERDOS"] = 0;
        }

        while (!q.empty()) {
            string current = q.front();
            q.pop();
            int currentNumber = erdosNumber[current];

            // Visit all co-authors of the current author
            for (string neighbor : graph[current]) {
                // If not already assigned an Erdos number
                if (erdosNumber.find(neighbor) == erdosNumber.end()) {
                    erdosNumber[neighbor] = currentNumber + 1;
                    q.push(neighbor);
                }
            }
        }

        // Prepare the result
        vector<string> result;
        for (string author : authors) {
            if (erdosNumber.find(author) != erdosNumber.end()) {
                result.push_back(author + " " + to_string(erdosNumber[author]));
            } else {
                // Authors without an Erdos number
                result.push_back(author);
            }
        }

        // Sort the result lexicographically
        sort(result.begin(), result.end());

        return result;
    }

    // Helper function to split a publication string by spaces into a vector of authors
    vector<string> split(string pub) {
        vector<string> result;
        string author = "";
        for (char c : pub) {
            if (c == ' ') {
                if (!author.empty()) {
                    result.push_back(author);
                    author = "";
                }
            } else {
                author += c;
            }
        }
        if (!author.empty()) result.push_back(author);
        return result;
    }
};
