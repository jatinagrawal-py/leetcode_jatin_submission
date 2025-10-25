class Solution {
public:
    int dp[100001];
    int solve(int n , vector<int>&cost , int i){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int j =1;
        int res = INT_MAX;
        if(i+j<=n){
            res = min(res,solve(n,cost,i+j)+cost[i]+1);
        }
        j++;
        if(i+j<=n){
            res = min(res,solve(n,cost,i+j)+cost[i+1]+4);
        }
        j++;
        if(i+j<=n){
            res = min(res,solve(n,cost,i+j)+cost[i+2]+9);
        }

        return dp[i]= res;
    }
    int climbStairs(int n, vector<int>& costs) {
        // 1 -> 1 + cost[j] 
        // 2 -> 4 + cost[j+1]
        // 3 -> 9 + cost[j+2]
        // 11 111 21 3
        memset(dp,-1,sizeof(dp));
        return solve(n,costs,0);
    }
};