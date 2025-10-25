class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                if (currentSum == target) {
                    return currentSum;  // Found the exact sum
                }

                if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                    closestSum = currentSum;  // Update the closest sum
                }

                if (currentSum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return closestSum;
    }
};