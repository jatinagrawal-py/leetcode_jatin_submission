class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,INT_MAX));

        queue<pair<pair<int,int>,int>>pq;
        pq.push({{start[0],start[1]},0});
        vis[start[0]][start[1]] = 0;

        vector<pair<int,int>>dir = {{1,0},{0,-1},{0,1},{-1,0}};

        while(!pq.empty()){
            int row = pq.front().first.first;
            int col = pq.front().first.second;
            int steps = pq.front().second;
            pq.pop();

            for(auto it:dir){
                int newi = row+it.first;
                int newj = col + it.second;
                if(newi<m && newj<n && newi>=0 && newj>=0 && grid[newi][newj]!=0 && vis[newi][newj]==INT_MAX){
                    pq.push({{newi,newj},steps+1});
                    vis[newi][newj]=steps+1;
                }
            }
        }

        vector<vector<int>>res;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]>=pricing[0] && grid[i][j]<=pricing[1] && vis[i][j]!=INT_MAX){
                    res.push_back({vis[i][j] , grid[i][j] , i , j});
                }
            }
        }

        sort(begin(res),end(res));

        vector<vector<int>>ans;

        for(int i = 0;i<min((int)res.size(),k);i++){
            ans.push_back({res[i][2],res[i][3]});
        }

        return ans;

    }
};