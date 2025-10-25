class Solution {
public:
    int result = -1;
    void dfs(int u , vector<int>& edges , vector<int>&count , vector<bool>&inr , vector<bool>&vis){
        if(u==-1){
            return;
        }
    
        vis[u]=true;
        inr[u]=true;
        int v = edges[u];

        if(v!=-1 && vis[v]==false){
            count[v] = count[u]+1;
            dfs(v,edges,count,inr,vis);
        }
        else if(v!=-1 && inr[v]==true){
            result = max(result,count[u]-count[v]+1);
        }

        inr[u] = false;
        
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool>vis(n,false);
        vector<int>count(n,1);
        vector<bool>inr(n,false);

        for(int i = 0;i<n;i++){
            
            if(vis[i]!=true){
                dfs(i,edges,count,inr,vis);
            }
        }

        return result;
    }
};