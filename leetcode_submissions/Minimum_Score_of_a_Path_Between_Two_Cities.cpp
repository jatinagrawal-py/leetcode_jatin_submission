class Solution {
public:
    void dfs(unordered_map<int,vector<pair<int,int>>>&adj , vector<int>&vis , int u , int &mini){
        vis[u] = 1;

        for(auto it:adj[u]){
            int v = it.first;
            int cost = it.second;
                            mini = min(mini,cost);

            if(vis[v]==0){
                dfs(adj,vis,v,mini);
            }
        }
        return ;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto it:roads){
            int u = it[0];
            int v = it[1];
            int price = it[2];
            adj[u].push_back({v,price});
            adj[v].push_back({u,price});
        }
        int mini = INT_MAX;
        vector<int>vis(n+1,0);
        dfs(adj,vis,1,mini);

        return mini;
    }
};