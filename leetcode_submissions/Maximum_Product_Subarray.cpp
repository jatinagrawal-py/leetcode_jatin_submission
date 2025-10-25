class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int p = 1;
        int suf = 1;
        for(int i =0;i<nums.size();i++){
            if(p==0)p=1;
            if(suf==0)suf=1;

            p = p*nums[i];
            suf = suf*nums[nums.size()-i-1];

            maxi = max(maxi,max(p,suf));
        }

        return maxi;
    }
};