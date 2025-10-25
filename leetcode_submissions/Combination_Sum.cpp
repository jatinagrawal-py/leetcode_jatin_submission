class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target, vector<int>& path, int idx, int sum) {
        if (sum == target) {
            ans.push_back(path);
            return;
        }
        if (sum > target) return;

        for (int i = idx; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            solve(candidates, target, path, i, sum + candidates[i]); 
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        solve(candidates, target, path, 0, 0);
        return ans;
    }
};
