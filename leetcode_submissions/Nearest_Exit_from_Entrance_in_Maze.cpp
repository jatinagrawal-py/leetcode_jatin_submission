class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int u = entrance[0];
        int v = entrance[1];

        queue<pair<pair<int,int>,int>>pq;
        vector<pair<int,int>>dir = {{1,0},{0,-1},{0,1},{-1,0}};
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        pq.push({{u,v},0});
        vis[u][v]=true;

        while(!pq.empty()){
            int i = pq.front().first.first;
            int j = pq.front().first.second;
            int steps = pq.front().second;
            pq.pop();

            if((i==0 || j ==0 || i==m-1 || j==n-1) && steps>0){
                return steps;
            }

            for(auto it:dir){
                int newi = i + it.first;
                int newj = j + it.second;
                if(newi>=0 && newj>=0 && newi<m && newj<n && maze[newi][newj]=='.' && vis[newi][newj]==false){
                    pq.push({{newi,newj},steps+1});
                    vis[newi][newj]=true;
                }
            }
        }
        return -1;
    }
};