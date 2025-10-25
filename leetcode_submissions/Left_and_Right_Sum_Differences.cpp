class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(0);
        int right = 0;

        for(int i=0;i<n;i++){
            right = right + nums[i];
        }

        int left =0;

        for(int i=0;i<n;i++){
            right = right - nums[i];
            int temp = left-right;
            if(right>left){
                temp = -1*temp;
            }
            ans.push_back(temp);
            left = left+nums[i];
        }
        return ans;
    }
};