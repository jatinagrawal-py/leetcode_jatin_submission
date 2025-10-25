class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;
        unordered_map<int, vector<int>> adj;
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        q.push(1);
        vector<bool> vis(edges.size() + 2, false);
        vis[1] = true;
        int depth = 0;

        while (!q.empty()) {
            int si = q.size();
            while (si--) {
                int u = q.front();
                q.pop();
                for (int it : adj[u]) {
                    if (!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
            depth++;
        }

        int pathLength = depth - 1;

        long long dp_even = 1, dp_odd = 0;

        for (int i = 0; i < pathLength; ++i) {
            long long new_even = (dp_even + dp_odd) % MOD;
            long long new_odd = (dp_even + dp_odd) % MOD;
            dp_even = new_even;
            dp_odd = new_odd;
        }

        return dp_odd;
    }
};
