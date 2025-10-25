class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;

        // Calculate the sum of the first k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double maxsum = sum;

        // Slide the window through the array
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k]; // Add the next element, remove the first element of the previous window
            maxsum = max(maxsum, sum);   // Update the maximum sum
        }

        return maxsum / k; // Return the maximum average
    }
};
