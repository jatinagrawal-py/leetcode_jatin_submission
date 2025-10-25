class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0;
        int i = 0;
        int j = 0;
        int maxi = 0;

        while(j<nums.size()){
            if(nums[j]==0)count++;
            while(count>1){
                if(nums[i]==0)count--;
                i++;
            }
            if(count<=1){
                maxi = max(maxi,(j-i));
            }
            j++;
        }
        return maxi;
    }
};