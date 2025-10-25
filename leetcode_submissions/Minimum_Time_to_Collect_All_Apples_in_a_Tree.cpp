class Solution {
public:
    int DFS(unordered_map<int,vector<int>>&adj , vector<bool>& hasApple , int u , int parent){
        int time = 0;

        for(auto it:adj[u]){
            if(it==parent)continue;

            int time_child = DFS(adj,hasApple , it,u);

            if(time_child>0 || hasApple[it]==true){
                time  = time + time_child + 2;
            }
        }

        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adj;

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        return DFS(adj,hasApple,0,-1);
    }
};