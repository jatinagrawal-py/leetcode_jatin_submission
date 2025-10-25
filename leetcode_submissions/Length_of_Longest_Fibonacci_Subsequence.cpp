class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n,2));
        int max_ele = 0;

        unordered_map<int,int>mpp;
        for(int i = 0;i<n;i++){
            mpp[arr[i]] = i;
        }

        for(int j = 1;j<n;j++){
            for(int k = j+1;k<n;k++){
                int target = arr[k]-arr[j];
                if(mpp.count(target) && mpp[target]<j){
                    int i = mpp[target];
                    dp[j][k] = dp[i][j]+1; 
                }
                max_ele = max(max_ele,dp[j][k]);
            }
        }

        if(max_ele<3)return 0;

        return max_ele;
    }
};