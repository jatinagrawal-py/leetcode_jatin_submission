class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& stone, int i) {
        if (i >= n) return 0;
        if (dp[i] != INT_MIN) return dp[i];

        int stones = 0;
        int res = INT_MIN; 
        for (int x = 0; x < 3 && i + x < n; x++) {
            stones += stone[i + x];
            res = max(res, stones - solve(stone, i + x + 1));
        }
        return dp[i] = res;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int ans = solve(stoneValue, 0);
        if (ans == 0) return "Tie";
        if (ans > 0) return "Alice";
        return "Bob";
    }
};
