class Solution {
public:
    int dp[501];
    int solve(vector<int>& arr, int k , int i){
        if(i>=arr.size())return 0;
        if(dp[i]!=-1)return dp[i];

        int res = INT_MIN;
        int maxi = INT_MIN;

        for(int j = i;j<arr.size() && (j-i+1)<=k ;j++){
            maxi = max(maxi,arr[j]);
            res = max(res,maxi*(j-i+1)+solve(arr,k,j+1));
        }

        return dp[i]= res;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(arr,k,0);
    }
};