class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        for (auto it : queries) {
            int sum = 0;
            int len = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (sum + nums[i] > it) {
                    break;
                }
                sum += nums[i];
                len++;
            }
            ans.push_back(len);
        }
        
        return ans;
    }
};
