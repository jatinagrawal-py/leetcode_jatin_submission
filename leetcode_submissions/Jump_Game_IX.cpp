class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        vector<int>prefmax(n);
        vector<int>suffmin(n);

        prefmax[0] = nums[0];
        suffmin[n-1] = nums[n-1];

        for(int i = 1;i<n;i++)prefmax[i] = max(prefmax[i-1],nums[i]);

        for(int i = n-2;i>=0;i--)suffmin[i] = min(suffmin[i+1],nums[i]);

        ans[n-1] = prefmax[n-1];

        for(int i = n-2;i>=0;i--){
            ans[i] = prefmax[i];
            if(prefmax[i]>suffmin[i+1]){
                ans[i] = max(prefmax[i],ans[i+1]);
            }
        }

        return ans;
    }
};