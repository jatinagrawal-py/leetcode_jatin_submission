class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& moveCost,
              int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i == m - 1) return grid[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        int res = INT_MAX;
        for (int k = 0; k < n; ++k) {
            int cost = grid[i][j] + moveCost[grid[i][j]][k] +
                        solve(grid, moveCost, i + 1, k, m, n, dp);
            res = min(res, cost);
        }

        return dp[i][j] = res;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = INT_MAX;
        for (int j = 0; j < n; ++j) {
            ans = min(ans, solve(grid, moveCost, 0, j, m, n, dp));
        }

        return ans;
    }
};
