#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i], parent);
    }

    void unionn(int x, int y, vector<int>& parent) {
        int rootx = find(x, parent);
        int rooty = find(y, parent);
        if (rootx != rooty) {
            parent[rooty] = rootx;
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<vector<int>> adj(n); 

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (find(u, parent) != find(v, parent)) {
                unionn(u, v, parent);
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; i++) {
            int root = find(i, parent);
            components[root].push_back(i);
        }

        int ans = 0;
        for (auto& [root, nodes] : components) {
            int size = nodes.size();
            int edgeCount = 0;

            for (int node : nodes) {
                edgeCount += adj[node].size();
            }

            edgeCount /= 2;

            if (edgeCount == (size * (size - 1)) / 2) {
                ans++;
            }
        }

        return ans;
    }
};
