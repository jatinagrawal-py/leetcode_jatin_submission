class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> ans(0);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1; i = i+2){
            ans.push_back(nums[i+1]);
            ans.push_back(nums[i]);
        }
        return ans;
    }
};