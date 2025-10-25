class Solution {
public:
    bool dfs(int i , int j , int n , int m , vector<vector<int>>& grid){
        if(i>=n || i<0 || j>=m || j<0){
            return false;
        }

        if(grid[i][j]==1)return true;

        grid[i][j]=1;

        bool left = dfs(i-1,j,n,m,grid);
        bool right = dfs(i+1,j,n,m,grid);
        bool bottom = dfs(i,j-1,n,m,grid);
        bool top = dfs(i,j+1,n,m,grid);

        if(left && right && bottom && top)return true;


        return false;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0;i<n ;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]!=1){
                    if(dfs(i,j,n,m,grid)){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};