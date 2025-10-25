class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        //1,2,2,5,6,6
        sort(nums.begin(),nums.end());
        int sum = 0;

        for(int i = nums.size()-1;i>=0;i=i-2){
            sum = sum + min(nums[i],nums[i-1]);
        }

        return sum;
    }
};