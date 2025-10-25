class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2 , int i , int j){
        if(i>=nums1.size() || j>=nums2.size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(nums1[i]==nums2[j]){
            return dp[i][j]= 1+solve(nums1,nums2,i+1,j+1);
        }

        return dp[i][j]= max( solve(nums1,nums2,i+1,j) , solve(nums1,nums2,i,j+1));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        memset(dp,-1,sizeof(dp));

        if(n1<=n2){
            return solve(nums1,nums2,0,0);
        }

        return solve(nums2,nums1,0,0);

        // 
    }
};