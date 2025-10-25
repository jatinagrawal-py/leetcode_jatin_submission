class Solution { 
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Step 1: Count the frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Custom sort based on frequency and value
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b]) return a > b; // If same frequency, sort in decreasing order
            return freq[a] < freq[b]; // Otherwise, sort by increasing frequency
        });

        return nums;
    }
};