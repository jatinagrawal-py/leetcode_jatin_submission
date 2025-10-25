class Solution {
public:
    int solve(vector<int>& nums, int target , int sum , int i){
        if(i==nums.size()){
            if(sum==target)return 1;
            return 0;
        }

        int pos= solve(nums,target,sum+nums[i],i+1);
        int neg= solve(nums,target,sum-nums[i],i+1);

        return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }
};