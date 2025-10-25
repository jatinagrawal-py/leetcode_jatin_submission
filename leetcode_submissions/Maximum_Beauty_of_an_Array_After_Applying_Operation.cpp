class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxele = *max_element(nums.begin(), nums.end()) + k + 2;
        int offset = k; // shift everything by +k
        vector<int> prefix(maxele + offset + 1, 0);

        for (auto it : nums) {
            prefix[it - k + offset]++;
            prefix[it + k + 1 + offset]--;
        }

        int sum = 0, maxi = 0;
        for (auto &it : prefix) {
            sum += it;
            maxi = max(maxi, sum);
        }
        return maxi;
    }

};