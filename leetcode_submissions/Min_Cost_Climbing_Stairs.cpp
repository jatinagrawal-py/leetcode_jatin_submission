class Solution {
public:
    int dp[1001];
    int solve(vector<int>& cost , int i){
        if(i>=cost.size())return 0;

        if(dp[i]!=-1)return dp[i];

        int res = INT_MAX;
        res = min(res,cost[i]+solve(cost,i+1));
        res = min(res,cost[i]+solve(cost,i+2));

        return dp[i]= res;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(solve(cost,0),solve(cost,1));
    }
};