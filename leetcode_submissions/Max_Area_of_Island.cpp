class Solution {
public:
    vector<vector<int>>dir = {{1,0},{0,-1},{0,1},{-1,0}};
    int dfs(vector<vector<int>>& grid , vector<vector<int>>& vis , int i , int j , int m , int n){
        
        vis[i][j]=1;
        int count = 1;
        for(auto it:dir){
            int newi = i + it[0];
            int newj = j+ it[1];
            if(newi>=0 && newj>=0 && newi<m && newj<n){
                if(grid[newi][newj]==1 && vis[newi][newj]==0){
                    count+=(dfs(grid,vis,newi,newj,m,n));
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        int maxi = INT_MIN;

        for(int i  =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(vis[i][j]!=1 && grid[i][j]==1){
                    maxi = max(dfs(grid,vis,i,j,m,n),maxi);
                }
            }
        }

        return maxi==INT_MIN?0:maxi;
    }
};