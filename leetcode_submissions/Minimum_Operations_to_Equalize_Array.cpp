class Solution {
public:
    int minOperations(vector<int>& nums) {
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]){
                return 1;
            }
        }

        return 0;
    }
};