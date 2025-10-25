class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp, int i) {
        ans.push_back(temp);

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) continue;  
            temp.push_back(nums[j]);
            solve(ans, nums, temp, j + 1);  
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, nums, temp, 0);
        return ans;
    }
};
