#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple>

using namespace std;

class BlockEnemy {
public:
    int minEffort(int N, vector<string> roads, vector<int> occupiedTowns) {
        vector<tuple<int, int, int>> edges;
        for (string road : roads) {
            stringstream ss(road);
            int a, b, e;
            ss >> a >> b >> e;
            edges.push_back({e, a, b});
        }

        // Sort edges by effort in ascending order
        sort(edges.begin(), edges.end());

        // Use Kruskal's algorithm to build the MST
        initUnionFind(N);
        vector<tuple<int, int, int>> mst;
        for (const auto& edge : edges) {
            int effort = get<0>(edge);
            int u = get<1>(edge);
            int v = get<2>(edge);

            if (!connected(u, v)) {
                unite(u, v);
                mst.push_back(edge);
            }
        }

        // Create a new UnionFind for checking occupied towns connectivity
        initUnionFind(N);
        int totalEffort = 0;

        // Mark occupied towns for quick lookup
        vector<bool> isOccupied(N, false);
        for (int town : occupiedTowns) {
            isOccupied[town] = true;
        }

        // Remove edges in reverse order, starting from the most expensive
        for (auto it = mst.rbegin(); it != mst.rend(); ++it) {
            int effort = get<0>(*it);
            int u = get<1>(*it);
            int v = get<2>(*it);

            // If u and v are connected and are both occupied, then remove the edge
            if (connected(u, v) && isOccupied[find(u)] && isOccupied[find(v)]) {
                totalEffort += effort;
            } else {
                unite(u, v);
            }
        }

        return totalEffort;
    }

    vector<int> parent, rank;

    void initUnionFind(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
