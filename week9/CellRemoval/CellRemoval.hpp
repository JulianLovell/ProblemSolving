#include <iostream>
#include <vector>

using namespace std;

class CellRemoval {
public:
    // Helper function for DFS to count remaining cells
    void dfs(int node, const vector<vector<int>>& tree, vector<bool>& deleted, int& count) {
        // If the node is deleted, skip it
        if (deleted[node]) return;
        
        // Increase count since this cell is not deleted
        count++;
        
        // Recursively visit all children
        for (int child : tree[node]) {
            dfs(child, tree, deleted, count);
        }
    }

    int cellsLeft(vector<int> parentCell, int deletedCell) {
        // Number of cells
        int n = parentCell.size();
        // Tree representation as an adjacency list
        vector<vector<int>> tree(n);
        
        // Build the tree from the parentCell array
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (parentCell[i] == -1) {
                // Root of the tree
                root = i;
            } else {
                // Add child to its parent
                tree[parentCell[i]].push_back(i);
            }
        }

        // Mark the deleted cell and all its descendants as deleted
        // Initially no cells are deleted
        vector<bool> deleted(n, false);
        // Mark the deleted cell
        deleted[deletedCell] = true;
        
        // If the root itself is deleted, return 0
        if (deletedCell == root) return 0;
        
        // Count remaining cells using DFS
        int remainingCells = 0;
        // Start DFS from the root
        dfs(root, tree, deleted, remainingCells);

        // Return the count of remaining cells
        return remainingCells;
    }
};
