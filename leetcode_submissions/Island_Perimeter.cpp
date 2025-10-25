class Solution {
public:
    int dfs(int i , int j ,vector<vector<int>>& grid , int m , int n){
        if(i<0 || i>=m || j<0 || j>=n){
            return 1;
        }

        if(grid[i][j]==0){
            return 1;
        }
        if(grid[i][j]==-1){
            return 0;
        }

        grid[i][j]=-1;

        int hehe1 = dfs(i,j+1 , grid , m , n);
        int hehe2 = dfs(i+1,j , grid , m , n);
        int hehe3 = dfs(i,j-1 , grid , m , n);
        int hehe4 = dfs(i-1,j , grid , m , n);


        return hehe1 + hehe2 + hehe3 + hehe4;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        bool hehe = false;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    return dfs(i,j,grid,m,n);
                }
            }
        }

        return -1;
    }
};