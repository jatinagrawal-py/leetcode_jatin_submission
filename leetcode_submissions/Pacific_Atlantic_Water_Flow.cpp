class Solution {
public:
    vector<pair<int,int>>dir = {{1,0},{0,-1},{0,1},{-1,0}};
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i , int j , bool ispacific , int n , int m){
        if (ispacific) {
            if (vis[i][j] == 0) vis[i][j] = 1;  
        } else {
            if (vis[i][j] == 1) vis[i][j] = 2; 
            else if (vis[i][j] == 0) vis[i][j] = -1; 
        }

        if(ispacific){
            for(auto it:dir){
                int newi = i+it.first;
                int newj = j+it.second;
                if(newi<n && newj<m && newi>=0 && newj>=0){
                    if(vis[newi][newj]==0 && grid[newi][newj]>=grid[i][j]){
                        dfs(grid,vis,newi,newj,true,n,m);
                    }
                }
            }
        }
        else{
            for(auto it:dir){
                int newi = i+it.first;
                int newj = j+it.second;
                if(newi<n && newj<m && newi>=0 && newj>=0){
                    if((vis[newi][newj]==0 || vis[newi][newj]==1) && grid[newi][newj]>=grid[i][j]){
                        dfs(grid,vis,newi,newj,false,n,m);
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i = 0;i<n;i++){
            if(vis[i][0]==0){
                dfs(grid,vis,i,0,true,n,m);
            }
        }
        for(int j = 0;j<m;j++){
            if(vis[0][j]==0){
                dfs(grid,vis,0,j,true,n,m);
            }
        }
        for(int i = 0;i<n;i++){
            if(vis[i][m-1]==1 || vis[i][m-1]==0){
                dfs(grid,vis,i,m-1,false,n,m);
            }
        }
        for(int j = 0;j<m;j++){
            if(vis[n-1][j]==1 || vis[n-1][j]==0){
                dfs(grid,vis,n-1,j,false,n,m);
            }
        }

        vector<vector<int>>res;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j]==2)res.push_back({i,j});
            }
        }

        return res;

    }
};