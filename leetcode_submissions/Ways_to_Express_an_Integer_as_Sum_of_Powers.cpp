class Solution {
public:
    int mod = 1e9 + 7;
    int dp[301][301];
    long long ipow(int i , int power){
        long long res = 1;
        while(power--){
            res*=i;
        }

        return res;
    }

    int solve(int n , int power , int start){

        if(n==0){
            return 1;
        }

        if(n<0)return 0;

        if(dp[n][start]!=-1) return dp[n][start]; 

        int res = 0;

        for(int i = start ; ipow(i,power) <=n; i++){
            int hehe = ipow(i,power);
           
            res = (res+solve(n-hehe,power,i+1))%mod;
            
        }

        return dp[n][start]= res;
    }
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return solve(n,x,1);
    }
};