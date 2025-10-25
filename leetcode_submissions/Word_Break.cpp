class Solution {
public:
    int dp[301];
    bool solve(string &s, unordered_set<string>& st, int i) {
        if (i < 0) return true;
        if (dp[i] !=-1 ) return dp[i];

        string curr = "";
        for (int j = i; j >= 0; --j) {
            curr = s[j] + curr; 
            if (st.find(curr) != st.end()) {
                if (solve(s, st, j - 1)) {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        memset(dp,-1,sizeof(dp));
        return solve(s, st, n - 1);
    }
};
