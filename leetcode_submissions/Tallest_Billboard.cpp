class Solution {
public:
    int dp[21][10001];
    int solve(vector<int>& rods , int i , int diff){
        if(i>=rods.size()){
            if(diff==0)return 0;

            return INT_MIN;
        }

        if(dp[i][diff+5001]!=-1) return dp[i][diff+5001];

        int nottake = solve(rods,i+1,diff);
        int takel1 = rods[i]+solve(rods,i+1,diff+rods[i]);
        int takel2 = rods[i]+solve(rods,i+1,diff-rods[i]);

        return dp[i][diff+5001] =  max({nottake , takel1 , takel2});
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(rods,0,0);

        if(ans==INT_MIN)return 0;

        return ans/2;
    }
};