class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;

        int f = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0 && f%2==0){
                result++;
                f++;
            }
            else if(nums[i]==1 && f%2==1){
                result++;
                f++;
            }
        }
        return result;
    }
};