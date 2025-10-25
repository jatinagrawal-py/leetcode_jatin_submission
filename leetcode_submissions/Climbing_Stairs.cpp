class Solution {
public:
    int dp[46];
    int solve(int i){
        if(i==0){
            return 1;
        }
        if (i<0)return 0;

        if(dp[i]!=-1)return dp[i];

        int one = solve(i-1);
        int two = solve(i-2);

        return dp[i]= one+two;

    }
    int climbStairs(int n) {

        memset(dp,-1,sizeof(dp));

        dp[0]=1;

        for(int i = 1;i<=n;i++){

            int one = dp[i-1];
            int two = i<=1?0:dp[i-2];

            dp[i]= one+two;

        }
        
        return dp[n];

    }
};