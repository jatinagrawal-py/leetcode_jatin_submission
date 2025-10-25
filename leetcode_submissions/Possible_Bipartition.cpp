class Solution {
public:
    bool bfs(unordered_map<int,vector<int>>&adj , vector<int>&color , int i){
        color[i] = 0;
        queue<int>pq;
        pq.push(i);

        while(!pq.empty()){
            int u = pq.front();
            pq.pop();
            for(auto it:adj[u]){
                if(color[it]==color[u])return false;
                if(color[it]==-1){
                    color[it] = 1-color[u];
                    pq.push(it);
                }
            }
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;
        for(auto it:dislikes){
            int u = it[0]-1;
            int v = it[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>color(n,-1);

        for(int i = 0;i<n;i++){
            if(color[i]==-1){
                if(bfs(adj,color,i)==false)return false;
            }
        }
        return true;
    }
};