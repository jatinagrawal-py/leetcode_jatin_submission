class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        long long count = 0;
        int minval = -1;
        int maxval = -1;
        int culprit = -1;

        for(int i  =0;i<nums.size();i++){
            if(nums[i]==mink){
                minval = i;
            }
            if(nums[i]==maxk){
                maxval = i;
            }
            if(nums[i]<mink || nums[i]>maxk){
                culprit = i;
            }

            int temp = min(minval,maxval);
            temp = temp - culprit;
            if(temp>0){
                count+=temp;
            }
        }

        return count;
    }
};