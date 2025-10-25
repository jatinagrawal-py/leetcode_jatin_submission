class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 2;
        int count = 2;
        for(int i = 2;i<nums.size();i++){
            if(nums[i]==nums[i-1]+nums[i-2]){
                count++;
                ans = max(count,ans);
            }
            else{
                count = 2;
            }
        }
        return ans;
    }
};