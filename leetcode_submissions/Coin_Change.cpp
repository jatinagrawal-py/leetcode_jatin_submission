class Solution {
public:
    int solve(vector<int>& coins, int amount , int i , vector<vector<int>>&dp){
        if(i==0){
            if(amount%coins[i]==0)return amount/coins[i];
            return 1e9;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];

        int nottake = 0 + solve(coins,amount,i-1,dp);
        int take = 1e9;
        if(coins[i]<=amount){
            take = 1 + solve(coins,amount-coins[i],i,dp);
        }

        return dp[i][amount]= min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        
       
        int ans = solve(coins,amount,n-1,dp);
        if(ans<1e9)return ans;
        
        return -1;
    }
};