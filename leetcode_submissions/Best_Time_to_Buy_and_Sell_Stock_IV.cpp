class Solution {
public:
    int dp[1001][2][101];
    int solve(vector<int>&prices , int i , int buy,int cap){
        if(cap==0)return 0;
        if(i==prices.size())return 0;

        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        int profit = 0;

        if(buy){
            profit = max((-prices[i]+solve(prices,i+1,0,cap)),solve(prices,i+1,1,cap));
        }
        else{
            profit = max((+prices[i]+solve(prices,i+1,1,cap-1)),solve(prices,i+1,0,cap));
        }

        return dp[i][buy][cap]= profit;
    }
    int maxProfit(int k, vector<int>& prices) {
         memset(dp,-1,sizeof(dp));
        return solve(prices,0,1,k);
    }
};