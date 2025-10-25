class Solution {
public:
    void dfs(unordered_map<int,vector<pair<int,int>>>&adj , vector<int>&vis , int u , int &ans){
        vis[u]=1;

        for(auto it:adj[u]){
            int v = it.first;
            int isreal = it.second;
            if(vis[v]==0){
                if(isreal){
                ans++;
            }
                dfs(adj,vis,v,ans);
            }
        }
        return;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }

        int ans = 0;
        vector<int>vis(n,0);
        dfs(adj,vis,0,ans);

        return ans;
    }
};