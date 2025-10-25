class Solution {
public:
    int mod = 1e9 + 7;
    int dp[100001];
    int solve(int low, int high, int zero, int one , int len){
        if(len>high)return 0;
        if(dp[len]!=-1)return dp[len];
        int count = 0;
        if(len<=high && len>=low)count++;

        int addone = solve(low,high,zero,one,len+one);
        int addzero = solve(low,high,zero,one,len+zero);

        count=(count+addone)%mod;
        count=(count+addzero)%mod;


        return dp[len]= count;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp , -1, sizeof(dp));
        return solve(low,high,zero,one,0);
    }
};