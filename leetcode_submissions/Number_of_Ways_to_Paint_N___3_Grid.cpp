class Solution {
public:
    vector<string> hehe; // all valid rows
    unordered_map<int, vector<int>> compatible; // valid transitions
    vector<vector<int>> dp;
    long long mod = 1e9 + 7;

    // Generate all valid rows of length 3 (no two adjacent same colors)
    void generate(string built , char prev , int len , string colors){
        if(len == 3){
            hehe.push_back(built);
            return;
        }
        
        for(char ch : colors){
            if(ch == prev) continue;
            generate(built + ch, ch, len + 1, colors);
        }
    }

    // Check if two row patterns are compatible (no same color in any column)
    bool isCompatible(const string &a, const string &b) {
        for(int i = 0; i < 3; i++) {
            if(a[i] == b[i]) return false;
        }
        return true;
    }

    // DP function
    int solve(int prevIndex, int rem) {
        if(rem == 0) return 1;

        if(dp[prevIndex][rem] != -1) return dp[prevIndex][rem];

        long long totalWays = 0;
        for(int nextIndex : compatible[prevIndex]) {
            totalWays = (totalWays + solve(nextIndex, rem - 1)) % mod;
        }

        return dp[prevIndex][rem] = totalWays;
    }

    int numOfWays(int n) {
        generate("", '#', 0, "RGB");

        int m = hehe.size();

        // Build compatibility map
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(isCompatible(hehe[i], hehe[j])) {
                    compatible[i].push_back(j);
                }
            }
        }

        // Initialize DP table
        dp = vector<vector<int>>(m, vector<int>(n, -1));

        long long res = 0;
        // Start from every valid row as the first row
        for(int i = 0; i < m; i++) {
            res = (res + solve(i, n - 1)) % mod;
        }

        return res;
    }
};
