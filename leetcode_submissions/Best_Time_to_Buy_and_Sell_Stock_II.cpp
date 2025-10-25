class Solution {
public:
    int dp[30001][2];
    int solve(vector<int>&prices , int i , int buy){
        if(i==prices.size())return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit = 0;

        if(buy){
            profit = max((-prices[i]+solve(prices,i+1,0)),solve(prices,i+1,1));
        }
        else{
            profit = max((+prices[i]+solve(prices,i+1,1)),solve(prices,i+1,0));
        }

        return dp[i][buy]= profit;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,1);

    }
};