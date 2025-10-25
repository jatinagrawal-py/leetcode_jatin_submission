class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[1001][1001]; 

    int solve(string& target, vector<vector<int>>& freq, int i, int j, int n) {
        if (i == target.size()) return 1; 
        if (j == n) return 0;             

        if (dp[i][j] != -1) return dp[i][j];

        long long notTaken = solve(target, freq, i, j + 1, n);

        long long taken = 0;
        int charIdx = target[i] - 'a';
        if (freq[charIdx][j] > 0) {
            taken = (1LL * freq[charIdx][j] * solve(target, freq, i + 1, j + 1, n)) % MOD;
        }

        return dp[i][j] = (taken + notTaken) % MOD;
    }

    int numWays(vector<string>& words, string target) {
        int m = words.size();
        int n = words[0].size();
        memset(dp, -1, sizeof(dp));

        vector<vector<int>> freq(26, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                freq[words[i][j] - 'a'][j]++;
            }
        }

        return solve(target, freq, 0, 0, n);
    }
};
