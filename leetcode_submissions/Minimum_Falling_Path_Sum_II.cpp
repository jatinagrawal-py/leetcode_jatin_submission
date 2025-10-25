class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& grid,int n , int i , int prevcol){
        if(i>=n)return 0;
        if(dp[i][prevcol+1]!=-1e5) return dp[i][prevcol+1]; 
        int res = INT_MAX;
        for(int k = 0;k<n;k++){
            if(prevcol!=k){
                res = min(res,grid[i][k]+solve(grid,n,i+1,k));
            }
        }

        return dp[i][prevcol+1]= res;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        dp.assign(201,vector<int>(202,-1e5));
        return solve(grid,n,0,-1);
    }
};