class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>t(n,1);
        int lis = 1;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j]){
                    t[i] = max(t[i],t[j]+1);
                    lis = max(t[i],lis);
                }
            }
        }

        return lis;
    }
};