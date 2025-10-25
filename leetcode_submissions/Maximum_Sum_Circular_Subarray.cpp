class Solution {
public:
    int maxka(vector<int>& nums){
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxi){
                maxi = sum;
            }
            if(sum<0){
                sum = 0;
            }
        }
        return maxi;
    }
    int minka(vector<int>& nums){
        int sum = 0;
        int maxi = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<maxi){
                maxi = sum;
            }
            if(sum>0){
                sum = 0;
            }
        }
        return maxi;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        for(auto it:nums){
            sum+=it;
        }
        int maxika = maxka(nums);
        int minika = minka(nums);
        int maxika2 = sum - minika;

        if(maxika>0)return max(maxika , maxika2);

        return maxika;
    }
};