class Solution {
public:
    int dp[100][100];
    int solve(int i , int j , vector<vector<int>>& grid , int m , int n){
        if(i>=0 && j>=0 && grid[i][j]==1)return 0;
        if(i==0 && j==0)return 1;
        if(i<0 || j<0)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int up  = solve(i-1,j,grid,m,n);
        int down  = solve(i,j-1,grid,m,n);
        return dp[i][j]= up+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m = grid.size();
        int n = grid[0].size();
        return solve(m-1,n-1,grid,m,n);
    }
};