class Solution {
public:
    void dfs(vector<vector<int>>& graph , vector<bool>&vis , vector<bool>& inrec, int u){
        vis[u] = true;
        inrec[u] = true;

        for(auto it:graph[u]){
            if(vis[it]==false){
                dfs(graph , vis , inrec , it);
            }
            if(vis[it]==true && inrec[it]==true){
                return;
            }
        }
        inrec[u]=false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;

        int n = graph.size();

        vector<bool>vis(n,false);
        vector<bool>inrec(n,false);

        for(int i = 0;i<n;i++){
            if(vis[i]!=true){
                dfs(graph,vis,inrec,i);
            }
        }

        for(int i = 0;i<n;i++){
            if(inrec[i]==false){
                ans.push_back(i);
            }
        }

        return ans;
    }
};