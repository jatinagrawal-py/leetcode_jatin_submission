class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans = 0;

        for(int i =0;i<nums.size()-1;i++){
            int x = lower-nums[i];
            int y = upper-nums[i];

            int xpair = lower_bound(nums.begin() + i + 1, nums.end(), x) - (nums.begin() + i + 1);
            int ypair = upper_bound(nums.begin() + i + 1, nums.end(), y) - (nums.begin() + i + 1);

            ans += (long long)(ypair - xpair);

        }


        return ans;
        
    }
};