class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionn(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) parent[pb] = pa; 
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        unordered_map<int, vector<int>> adj;
        for (auto &it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            mpp[vals[i]].push_back(i);
        }

        int res = n; 

        for (auto &it : mpp) {
            int val = it.first;
            auto &nodes = it.second;

            for (auto node : nodes) {
                for (auto nei : adj[node]) {
                    if (vals[nei] <= val) {
                        unionn(node, nei);
                    }
                }
            }

            unordered_map<int,int> count;
            for (auto node : nodes) {
                count[find(node)]++;
            }

            for (auto &kv : count) {
                int c = kv.second;
                res += (c * (c - 1)) / 2;
            }
        }

        return res;
    }
};
