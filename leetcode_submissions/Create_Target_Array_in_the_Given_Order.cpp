class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> ans(0);
        int temp =0;
        for(int i=0;i<n;i++){
            if(index[i]<=temp){
                ans.insert(ans.begin()+index[i],nums[i]);
                temp++;
            }
        }
        return ans;
    }
};