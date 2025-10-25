class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(auto it:nums){
            if(it<k){
                return -1;
            }
        }


        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());

        int dis = 1;

        for(int i = 1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]){
                dis++;
            }
        }

        if(nums[nums.size()-1]>k){
            return dis;
        }

        return dis-1;

    }
};