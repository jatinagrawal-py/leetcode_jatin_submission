class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>dp(n);
        for(int j= 0;j<n;j++){
            dp[j]=triangle[n-1][j];
        }

        for(int i = n-2;i>=0;i--){
            for(int j = 0;j<=i;j++){
                int d = dp[j] + triangle[i][j];
                int dg = dp[j+1] + triangle[i][j];
                dp[j] = min(d,dg);
            }
        }

        return dp[0];
    }
};