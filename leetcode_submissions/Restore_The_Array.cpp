#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int dp[100001];

    int solve(string &s, int k , int i){
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        long long num = 0;
        int ans = 0;

        for(int end = i; end < s.size(); end++){
            num = num * 10 + (s[end] - '0');
            if(num > k) break;

            ans = (ans + solve(s, k, end + 1)) % mod;
        }

        return dp[i] = ans;
    }

    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(s, k, 0);
    }
};
