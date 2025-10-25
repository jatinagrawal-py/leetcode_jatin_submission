class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);     // Add start
        cuts.push_back(n);                // Add end
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; ++len) {  // len = length of the subproblem
            for (int i = 0; i + len < m; ++i) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j],
                        cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
            }
        }

        return dp[0][m - 1];  // whole segment
    }
};
