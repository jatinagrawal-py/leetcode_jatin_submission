class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums , int i){
        if(i<0)return 0;
        if(i==0){
            return nums[i];
        }

        if(dp[i]!=-1)return dp[i];

        int take = nums[i] + solve(nums,i-2);
        int nottake = solve(nums,i-1);

        return dp[i]=max(take ,nottake);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));

        int n = nums.size();

        dp[0]=nums[0];

        for(int i = 1;i<n;i++){
            int take ;
            if(i<2){
                take = nums[i] ;
            }
            else{
                take = nums[i] + solve(nums,i-2);
            }
            int nottake = solve(nums,i-1);

            dp[i]=max(take ,nottake);
        }

        return dp[n-1];

        //return solve(nums,nums.size()-1);
    }
};