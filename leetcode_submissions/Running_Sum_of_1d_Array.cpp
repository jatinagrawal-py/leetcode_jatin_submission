class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(0) ;
        int ans1=0;
        for(int i=0;i<n;i++){
            ans1=0;
            for(int j=0;j<=i;j++){
                ans1 = ans1+ nums[j];
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};