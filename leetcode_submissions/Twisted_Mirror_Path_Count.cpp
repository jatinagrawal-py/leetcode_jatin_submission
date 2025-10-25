class Solution {
public:
    int dp[501][501][3];
    int mod = 1e9 + 7;

    int solve(vector<vector<int>>& grid , int i , int j , int m , int n , int whichstep){
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j][whichstep] != -1) return dp[i][j][whichstep];

        long long res = 0;

        if(grid[i][j] == 1) {
            if(whichstep == 1) { // last was right → must go down
                res += solve(grid, i+1, j, m, n, 2);
            } 
            else if(whichstep == 2) { // last was down → must go right
                res += solve(grid, i, j+1, m, n, 1);
            }
            
        } 
        else {
            // free cell → can move both ways
            res += solve(grid, i+1, j, m, n, 2);
            res += solve(grid, i, j+1, m, n, 1);
        }

        return dp[i][j][whichstep] = res % mod;
    }
    
    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m = grid.size(), n = grid[0].size(); // 1-> right jane ka 2-> niche jane kla 
        return solve(grid, 0, 0, m, n, 0);
    }
};
