class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;

       for(int i = 0;i<nums.size();i++){
            if(nums[i]==1){
                int j = i;
                while(j<nums.size() && nums[j]==1){
                    j++;
                }
                count = max(count,j-i);
                i = j;
            }
       }

       return count;
    }
};