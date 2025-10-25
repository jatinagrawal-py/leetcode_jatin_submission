class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& c) {
        const long long MOD = 1e9 + 7; 
        vector<int> hehe;
        int n = c.size();
        hehe.push_back(1);
        vector<long long> a(n + 2, -1); // memoization array
        a[0] = 1;

        unordered_map<int, pair<int, int>> mpp;

        for (auto it : c) {
            mpp[it[1]] = {it[0], it[2]};
        }

        for (int i = 1; i <= n; i++) {
            long long ans = 1;
            int u = i;
            while (u != 0) {
                if (a[u] != -1) {
                    ans = (ans * a[u]) % MOD;  // fix: add % MOD here
                    break;
                }
                ans = (ans * 1LL * mpp[u].second) % MOD;
                u = mpp[u].first;
            }
            a[i] = ans;
            hehe.push_back((int)ans);
        }

        return hehe;
    }
};
