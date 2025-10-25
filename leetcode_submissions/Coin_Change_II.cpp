class Solution {
public:
    long long dp[501][5001];
    int solve(int amount, vector<int>& coins , int i){
        if(i==0){
            if(amount%coins[i]==0)return 1;
            return 0;
        }

        if(dp[i][amount]!=-1)return dp[i][amount];

        int take = 0;
        if(coins[i]<=amount){
            take = solve(amount-coins[i],coins,i);
        }
        int nottake = solve(amount,coins,i-1);

        return dp[i][amount]= take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int n = coins.size();

        for(int j = 0;j<=amount;j++){
            if(j%coins[0]==0)dp[0][j]=1;
            else{
                dp[0][j]=0;
            }
        }

        for(int i = 1;i<n;i++){
            for(int cost = 0;cost<=amount;cost++){
                int take = 0;
                if(coins[i]<=cost){
                    take = dp[i][cost-coins[i]];
                }
                int nottake = dp[i-1][cost];

                dp[i][cost]= 1LL* take + nottake;
            }
        }

        return dp[n-1][amount];
        // return solve(amount,coins,coins.size()-1);
    }
};