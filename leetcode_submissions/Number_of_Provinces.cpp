class Solution {
private:
    void dfs(int i , vector<int> adj[] , vector<int> &vis){
        vis[i]=1;
        for(auto it : adj[i]){
            if(vis[it]==0){
                dfs(it,adj,vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat[0].size();
        vector<int> adj[n];
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(mat[i][j]==1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);
        int ans =0;
        for(int i =0;i<n;i++){
            if(vis[i]==0){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};