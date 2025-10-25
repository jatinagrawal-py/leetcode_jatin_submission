class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Step 1: Sort the array

        int minDiff = INT_MAX; // Step 2: Initialize min difference

        for(int i = 0; i < nums.size() - 1; i++) {
            minDiff = min(minDiff, nums[i + 1] - nums[i]); // Step 3: Find minimum adjacent difference
        }

        return minDiff; // Step 4: Return result
    }
};
