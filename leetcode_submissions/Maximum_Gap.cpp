class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxGap = 0;
        int n = nums.size();
        
        if (n < 2)
            return 0;
        
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        
        for (int i : nums) {
            minVal = min(minVal, i);
            maxVal = max(maxVal, i);
        }
        
        int bucketSize = ceil((double)(maxVal - minVal) / (n - 1));
        
        vector<int> minOfBucket(n, INT_MAX);
        vector<int> maxOfBucket(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == minVal || nums[i] == maxVal)
                continue;
            
            int bucketIndex = (nums[i] - minVal) / bucketSize;
            
            minOfBucket[bucketIndex] = min(minOfBucket[bucketIndex], nums[i]);
            maxOfBucket[bucketIndex] = max(maxOfBucket[bucketIndex], nums[i]);
        }
        
        int previous = minVal;
        for (int i = 0; i < n; i++) {
            if (minOfBucket[i] == INT_MAX && maxOfBucket[i] == -1)
                continue;
            
            maxGap = max(maxGap, minOfBucket[i] - previous);
            previous = maxOfBucket[i];
        }
        
        maxGap = max(maxGap, maxVal - previous);
        
        return maxGap;
        
    }
};