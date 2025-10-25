class Solution {
public:
    vector<vector<int>> dp; 
    
    bool solve(vector<int>& nums, int i, int sum) {
        if(sum == 0) return true;
        if(i >= nums.size() || sum < 0) return false;

        if(dp[i][sum] != -1) return dp[i][sum];

        bool take = solve(nums, i+1, sum - nums[i]);
        bool skip = solve(nums, i+1, sum);

        return dp[i][sum] = (take || skip);
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        int target = sum / 2;

        dp.assign(nums.size(), vector<int>(target+1, -1));
        return solve(nums, 0, target);
    }
};
