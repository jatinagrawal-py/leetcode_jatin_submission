class Solution {
public:
    vector<vector<int>> dp;  

    int solve(vector<int>& nums1, vector<int>& nums2 , int i , int j){
        if(i >= nums1.size() || j >= nums2.size()){
            return -10000000;
        }

        if(dp[i][j] != INT_MIN) return dp[i][j]; 

        int only1 = nums1[i] * nums2[j]; 
        int take = nums1[i] * nums2[j] + solve(nums1, nums2, i+1, j+1);
        int nottake = max(solve(nums1, nums2, i+1, j), solve(nums1, nums2, i, j+1));

        return dp[i][j] = max({take, nottake, only1});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp.assign(nums1.size(), vector<int>(nums2.size(), INT_MIN)); 
        return solve(nums1, nums2, 0, 0);
    }
};
