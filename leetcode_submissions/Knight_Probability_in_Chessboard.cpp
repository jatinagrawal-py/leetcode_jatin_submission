class Solution {
public:
    vector<pair<int,int>> dir = {{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2}};
    vector<vector<vector<double>>> dp;

    double solve(int n, int k, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n) return 0.0;
        if (k == 0) return 1.0;
        if (dp[k][i][j] != -1.0) return dp[k][i][j];

        double res = 0.0;
        for (auto &it : dir) {
            int newi = i + it.first;
            int newj = j + it.second;
            res += (1.0 / 8.0) * solve(n, k - 1, newi, newj);
        }
        return dp[k][i][j] = res;
    }

    double knightProbability(int n, int k, int row, int column) {
        dp.assign(k + 1, vector<vector<double>>(n, vector<double>(n, -1.0)));
        return solve(n, k, row, column);
    }
};
