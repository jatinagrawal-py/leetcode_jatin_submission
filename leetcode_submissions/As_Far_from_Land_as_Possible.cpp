class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>>vis(n,vector<int>(n,INT_MAX));

        queue<pair<pair<int,int>,int>>pq;

        int count0 = 0;
        int count1 = 0;
       
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                
                if(grid[i][j]==1){
                    count1++;
                    pq.push({{i,j},0});
                    vis[i][j] = 0;
                }
                else{
                    count0++;
                }
            }
        }

        vector<pair<int,int>>dir = {{1,0},{0,-1},{0,1},{-1,0}};

        while(!pq.empty()){
            int row = pq.front().first.first;
            int col = pq.front().first.second;
            int steps = pq.front().second;
            pq.pop();

            for(auto it:dir){
                int newi = row+it.first;
                int newj = col + it.second;
                if(newi<n && newj<n && newi>=0 && newj>=0 && grid[newi][newj]==0 && vis[newi][newj]==INT_MAX){
                    pq.push({{newi,newj},steps+1});
                    vis[newi][newj]=steps+1;
                }
            }
        }
        int ans = INT_MIN;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0){
                    ans = max(ans,vis[i][j]);
                }
            }
        }

        if(count0 == n*n || count1 == n*n)return -1;

        return ans;
    }
};