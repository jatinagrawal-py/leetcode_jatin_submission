class Solution {
public:
    int solve(unordered_map<int,vector<int>>&adj , int u , int v){
        int x = 0;

        for(auto it:adj[u]){
            x++;
        }

        for(auto it:adj[v]){
            if(it!=u){
                x++;
            }
        }

        return x;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,vector<int>>adj;

        for(auto it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans =  INT_MIN;
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                ans = max(ans,solve(adj,i,j));
            }
        }

        return ans;
    }
};