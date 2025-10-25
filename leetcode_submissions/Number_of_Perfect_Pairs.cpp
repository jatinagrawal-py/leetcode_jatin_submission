class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
       vector<long long> absValues;
        absValues.reserve(nums.size());
        
        for (int x : nums) {
            absValues.push_back(llabs((long long)x));
        }
        
        sort(absValues.begin(), absValues.end());
        
        long long pairCount = 0;
        int n = absValues.size();
        int right = 0;
        
        for (int left = 0; left < n; ++left) {
            if (right < left) right = left;
            while (right + 1 < n && absValues[right + 1] <= 2 * absValues[left]) {
                ++right;
            }
            pairCount += (right - left);
        }
        
        return pairCount;
    }
};