class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (k == 1) return true;
        int n = nums.size();
        unordered_set<int> st;

        for (int i = 0; i <= n - k; i++) {
            bool isInc = true;
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j - 1] >= nums[j]) {
                    isInc = false;
                    break;
                }
            }
            if (isInc) {
                st.insert(i);
                if (i >= k && st.find(i - k) != st.end())
                    return true;
            }
        }
        return false;
    }
};
