class Solution {
public:
    int dp[31][1001];
    int mod = 1e9+7;
    int solve(int n, int k, int target , int sum){
        if(n==0){
            if(target==sum)return 1;
            return 0;
        }

        if(dp[n][sum]!=-1) return dp[n][sum];
        

        int res = 0;

        for(int i = 1;i<=k;i++){
            if(sum+i<=target){
                res = (res+solve(n-1,k,target,sum+i))%mod;
            }
            
        }

        return dp[n][sum]= res;

    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,target,0);
    }
};