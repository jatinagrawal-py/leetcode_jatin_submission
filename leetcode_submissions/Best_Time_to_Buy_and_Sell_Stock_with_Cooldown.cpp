class Solution {
public:
    int dp[5001][2];
    int solve(vector<int>& prices , int i , int wannabuy){
        if(i>=prices.size())return 0;

        if(dp[i][wannabuy]!=-1)return dp[i][wannabuy];

        int maxi = INT_MIN;

        if(wannabuy){
            maxi = max(solve(prices,i+1,wannabuy) , -prices[i]+solve(prices,i+1,0));
        }
        else{
            maxi = max(solve(prices,i+1,wannabuy),+prices[i]+solve(prices,i+2,1));
        }

        return dp[i][wannabuy]= maxi;

    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,1);
        //1 means buy
    }
};