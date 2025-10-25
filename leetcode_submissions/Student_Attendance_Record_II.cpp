class Solution {
public:
    int dp[100001][3][4];
    int mod = 1e9 + 7;
    int solve(int n , int i , int absent , int late){
        if(i==n)return 1;
        if(i>n)return 0;
        if(dp[i][absent][late]!=-1) return dp[i][absent][late];
        int res = 0;
        if(absent<1){
            res = (res + solve(n,i+1,absent+1,0))%mod;
        }

        if(late<2){
            res =( res+solve(n,i+1,absent,late+1))%mod;
        }

        res = (res + solve(n,i+1,absent,0))%mod;

        return dp[i][absent][late]= res;
        
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0,0);
    }
};