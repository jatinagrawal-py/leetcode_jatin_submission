class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lsum = 0;
        int rsum = 0;
        int maxi = 0;
        for(int i = 0;i<k;i++){
            lsum+=nums[i];
        }

        maxi = lsum;
        int r = nums.size()-1;

        for(int i = k-1;i>=0;i--){
            lsum -=nums[i];
            rsum +=nums[r];
            r--;
            maxi = max(maxi,lsum+rsum);
        }

        return maxi;
    }
};