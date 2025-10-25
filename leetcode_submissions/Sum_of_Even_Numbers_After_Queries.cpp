class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // queries = val , index

        vector<int> ans;
    int sum = 0;

    // Calculate initial sum of even numbers
    for (int it : nums) {
        if (it % 2 == 0) {
            sum += it;
        }
    }

    // Process each query
    for (auto& it : queries) {
        int index = it[1];
        int val = it[0];

        // Remove the old value if it's even
        if (nums[index] % 2 == 0) {
            sum -= nums[index];
        }

        // Update nums[index] with val
        nums[index] += val;

        // Add the new value if it's even
        if (nums[index] % 2 == 0) {
            sum += nums[index];
        }

        ans.push_back(sum);
    }

    return ans;
    }
};