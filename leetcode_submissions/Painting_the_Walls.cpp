class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& cost, vector<int>& time , int i , int n){
        if(n<=0){
            return 0;
        }
        if(i==cost.size())return 1e9;

        if(dp[i][n]!=-1)return dp[i][n];

        int take = cost[i] + solve(cost,time,i+1,n-time[i]-1);
        int nottake = solve(cost,time,i+1,n);

        return dp[i][n]= min(take,nottake);

    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp,-1,sizeof(dp));
        int n = cost.size();
        return solve(cost,time,0,n);
    }
};