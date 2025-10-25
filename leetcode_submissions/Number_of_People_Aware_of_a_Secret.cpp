class Solution {
public:
    int dp[1001];
    int mod = 1e9 + 7;
    int solve(int n , int delay , int forget){
        if(n==1)return 1;
        if(n<=0)return 0;

        if(dp[n]!=-1)return dp[n];

        int res = 0;

        for(int i = n-forget+1 ; i<=n-delay ; i++){
            res = (res+solve(i,delay,forget))%mod;
        }

        return dp[n]= res;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total = 0;
        memset(dp,-1,sizeof(dp));

        for(int i = n-forget+1 ; i<=n ;i++){
            if(i>0){
                total = (total+solve(i,delay,forget))%mod;
            }
        }
        return total;
    }
};