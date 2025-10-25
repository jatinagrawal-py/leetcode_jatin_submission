class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int l = 0;
        int r = n-1;
        int ans = INT_MAX;
        while(l<=r){
            while(l<n-1 && nums[l]==nums[l+1]){
                l++;
            }
            while(r>0 && nums[r]==nums[r-1]){
                r--;
            }
            int mid = (l+r)/2;
            if(nums[mid]>=nums[l]){
                ans = min(ans,nums[l]);
                l = mid+1;
            }
            else{
                ans = min(ans,nums[mid]);
                r = mid-1;
            }
        }

        return ans;
    }
};