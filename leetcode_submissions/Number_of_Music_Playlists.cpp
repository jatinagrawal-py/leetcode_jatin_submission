class Solution {
public:
    int mod = 1e9+7;
    vector<vector<long long>> dp;

    long long solve(int n, int goal, int k , int count_songs , int count_unique){
        if(count_songs == goal){
            return count_unique == n ? 1 : 0;
        }

        if(dp[count_songs][count_unique] != -1) 
            return dp[count_songs][count_unique];

        long long res = 0;

        int rem_unique = n - count_unique;

        if(rem_unique > 0){
            res = (res + (1LL * rem_unique * solve(n,goal,k,count_songs+1,count_unique+1)) % mod) % mod;
        }

        if(count_unique > k){
            res = (res + (1LL * (count_unique - k) * solve(n,goal,k,count_songs+1,count_unique)) % mod) % mod;
        }

        return dp[count_songs][count_unique] = res;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        dp.assign(goal+1, vector<long long>(n+1, -1));
        return solve(n,goal,k,0,0);
    }
};
