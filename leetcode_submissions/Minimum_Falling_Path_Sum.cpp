class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>dp(n);
        for(int j = 0;j<n;j++){
            dp[j]= matrix[0][j];
        }

        for(int i = 1;i<n;i++){
            vector<int>temp(n);
            for(int j = 0;j<n;j++){
                int down = matrix[i][j] + dp[j];

                int left = INT_MAX;
                if(j-1>=0){
                    left = matrix[i][j] + dp[j-1];
                }

                int right = INT_MAX;
                if(j+1<n){
                    right = matrix[i][j] + dp[j+1];
                }

                temp[j] = min({down,left,right}); 
            }
            dp = temp;
        }

        int maxi = INT_MAX;
        for(auto it:dp){
            maxi = min(it,maxi);
        }

        return maxi;
    }
};