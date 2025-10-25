class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>hehe(n);
        int maxi = nums[n-1];
        int idx = n-1;
        for(int i = n-1;i>=0;i--){
            if(nums[i]>=maxi){
                maxi = nums[i];
                idx = i;
            }
            hehe[i] = idx;
        }
        int ans = -1;
        for(int i = 0;i<n;i++){
            if(nums[hehe[i]]>nums[i]){
                ans = max(ans , nums[hehe[i]]-nums[i]);
            }
        }

        return ans;
    }
};