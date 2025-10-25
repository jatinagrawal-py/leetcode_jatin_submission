class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;

        int i = 0;
        int j = 0;
        int pro = 1;

        while(j<nums.size()){
            pro*=nums[j];

            while(pro>=k && i<=j){
                pro/=nums[i];
                i++;
            }

            if(pro<k){
                count+=(j-i+1);
            }
            j++;
        }

        return count;
    }
};