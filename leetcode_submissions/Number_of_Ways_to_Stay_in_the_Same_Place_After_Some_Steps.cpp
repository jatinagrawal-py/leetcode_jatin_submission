class Solution {
public:
    int mod = 1e9+7;
    int dp[501][501];
    int solve(int steps, int lefty, int righty,int i){
        if(i==righty || i==lefty)return 0;
        if(steps==0){
            if(i==0)return 1;
            return 0;
        }

        if(dp[steps][i]!=-1)return dp[steps][i];

        int left = solve(steps-1,lefty,righty,i-1)%mod;
        int right = solve(steps-1,lefty,righty,i+1)%mod;
        int stay = solve(steps-1,lefty,righty,i)%mod;


        return dp[steps][i]= ((left+right)%mod+stay)%mod;

    }
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return solve(steps,-1,arrLen,0);
    }
};