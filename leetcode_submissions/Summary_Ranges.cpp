class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n == 0) return ans;

        int i = 0;
        int j = 1;

        while(j <= n) {
         
            if(j == n || nums[j] != nums[j - 1] + 1) {
                if(i == j - 1) {
                    ans.push_back(to_string(nums[i]));
                } else {
                    string left = to_string(nums[i]);
                    string right = to_string(nums[j - 1]);
                    ans.push_back(left + "->" + right);
                }
                i = j;
            }
            j++;
        }

        return ans;
    }
};
