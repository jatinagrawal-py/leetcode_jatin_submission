class Solution {
private:
    int timer = 1;
    
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tm[], int low[], vector<vector<int>> &brid) {
        vis[node] = 1;
        tm[node] = low[node] = timer;
        timer++;

        for (auto it : adj[node]) {
            if (it == parent) continue;  // Skip the edge to parent
            
            if (vis[it] == 0) {  // If the node is not visited, continue DFS
                dfs(it, node, vis, adj, tm, low, brid);
                
                // Update the low-link value
                low[node] = min(low[node], low[it]);
                
                // If the condition for a bridge is met, add the edge to the result
                if (low[it] > tm[node]) {
                    brid.push_back({it, node});
                }
            } else {
                // If it's a back edge, update the low-link value
                low[node] = min(low[node], tm[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        
        // Build adjacency list
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n, 0);
        int tm[n];
        int low[n];
        
        // Initialize time of discovery and low-link values
        fill(tm, tm + n, -1);
        fill(low, low + n, -1);

        vector<vector<int>> brid;  // Store bridges
        
        // In case the graph is disconnected, we need to loop over all nodes
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, adj, tm, low, brid);
            }
        }
        
        return brid;
    }
};
