class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int i = 0;

        while( j<nums.size() && nums[j]!=0){
            j++;
        }
        i = j+1;
        while(i<nums.size()){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
            i++;
        }
    }
};