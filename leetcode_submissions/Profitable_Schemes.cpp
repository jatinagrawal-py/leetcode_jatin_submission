class Solution {
public:
    int dp[101][101][101];
    int mod = 1e9+7;
    int solve(int n, int minProfit, vector<int>& group, vector<int>& profit , int i , int sum){
        if(n<=0 || i>=group.size()){
            if(minProfit<=sum)return 1;
            return 0;
        }
        if(dp[i][sum][n]!=-1)return dp[i][sum][n];
        int take = 0;
        if(n>=group[i]){
            int newProfit = min(minProfit, sum + profit[i]);
            take = (solve(n-group[i] , minProfit,group,profit,i+1,newProfit))%mod;
        }
        int nottake = (solve(n,minProfit,group,profit,i+1,sum))%mod;

        return dp[i][sum][n]= (nottake + take)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));

        return solve(n,minProfit,group,profit,0,0);
    }
};