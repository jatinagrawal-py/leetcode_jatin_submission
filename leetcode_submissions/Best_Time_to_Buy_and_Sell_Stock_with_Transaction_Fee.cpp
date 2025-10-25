class Solution {
public:
     int dp[50001][2];
    int solve(vector<int>&prices , int i , int buy, int fee){
        if(i==prices.size())return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit = 0;

        if(buy){
            profit = max((-prices[i]+solve(prices,i+1,0,fee)),solve(prices,i+1,1,fee));
        }
        else{
            profit = max((+prices[i]-fee +solve(prices,i+1,1,fee)),solve(prices,i+1,0,fee));
        }

        return dp[i][buy]= profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
         memset(dp,-1,sizeof(dp));
        return solve(prices,0,1,fee);
    }
};