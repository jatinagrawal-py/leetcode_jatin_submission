class Solution {
public:
    int dp[100001];
    bool solve(vector<int>& nums , int i){
        if(i>=nums.size())return true;

        if(dp[i]!=-1)return dp[i];

        bool cond1 = false;
        bool cond2 = false;
        bool cond3 = false;
        int n = nums.size();
        
        if(i<=n-2 && nums[i]==nums[i+1]){
            cond1 = solve(nums,i+2);
        }
        if(i<=n-3 && nums[i]==nums[i+1] && nums[i]==nums[i+2]){
            cond2 = solve(nums,i+3);
        }
        if(i<=n-3 && ((nums[i]-nums[i+1])==-1) && ((nums[i]-nums[i+2])==-2)){
            cond3 = solve(nums,i+3);
        }


        return dp[i]= cond1 || cond2 || cond3;

    }
    bool validPartition(vector<int>& nums) {
        // 2 same 
        // 3 same
        // 3 consecutive
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};