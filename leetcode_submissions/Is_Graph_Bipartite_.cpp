class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;

        vector<int> color(graph.size(),-1);
        for(int i = 0;i<graph.size()-1;i++){
            if(color[i]==-1){
                q.push(i);
        color[i]=1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto it : graph[u]){
                if(color[it]==color[u])return false;
                else if(color[it]==-1){
                    color[it] = 1-color[u];
                    q.push(it);
                }
            }
        }
            }
        }
        return true;
    }
};