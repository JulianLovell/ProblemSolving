#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple>

using namespace std;

class BlockEnemy {
public:
    // Structure to represent a road
    struct Road {
        int a;
        int b;
        int effort;
    };

    // Union-Find structure
    struct UnionFind {
        vector<int> parent;
        vector<bool> hasOccupied;

        UnionFind(int n, const vector<bool>& isOccupied) {
            parent.resize(n);
            hasOccupied.resize(n, false);
            for(int i=0;i<n;i++) {
                parent[i] = i;
                if(isOccupied[i]) {
                    hasOccupied[i] = true;
                }
            }
        }

        int find_set(int x) {
            if(parent[x] != x)
                parent[x] = find_set(parent[x]);
            return parent[x];
        }

        void union_set(int x, int y) {
            int fx = find_set(x);
            int fy = find_set(y);
            if(fx != fy) {
                parent[fy] = fx;
                hasOccupied[fx] = hasOccupied[fx] || hasOccupied[fy];
            }
        }

        bool connected_with_occupied(int x, int y) {
            return hasOccupied[find_set(x)] && hasOccupied[find_set(y)];
        }
    };

    int minEffort(int N, vector<string> roads, vector<int> occupiedTowns) {
        // Parse roads into Road structures
        vector<Road> roadList;
        for(const string& roadStr : roads) {
            stringstream ss(roadStr);
            int a, b, e;
            ss >> a >> b >> e;
            roadList.push_back(Road{a, b, e});
        }

        // Sort roads in descending order of effort
        sort(roadList.begin(), roadList.end(), [&](const Road& x, const Road& y) -> bool {
            return x.effort > y.effort;
        });

        // Mark occupied towns
        vector<bool> isOccupied(N, false);
        for(int town : occupiedTowns) {
            isOccupied[town] = true;
        }

        // Initialise Union-Find
        UnionFind uf(N, isOccupied);

        long long totalEffort = 0;

        // Process roads
        for(const Road& road : roadList) {
            int a = road.a;
            int b = road.b;
            int e = road.effort;

            // If connecting a and b would connect two occupied sets, cut the road
            if(uf.connected_with_occupied(a, b)) {
                totalEffort += e;
            }
            else {
                // Otherwise connect them
                uf.union_set(a, b);
            }
        }

        return (int)totalEffort;
    }
};
