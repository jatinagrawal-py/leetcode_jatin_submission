class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        long long sum = n * (n + 1LL) / 2;
        long long squareSum = n * (n + 1LL) * (2LL * n + 1) / 6;

        long long s = 0, ss = 0;
        for (int it : nums) {
            s += it;
            ss += (1LL * it * it);  // Use long long multiplication
        }

        long long a = squareSum - ss; // a^2 - b^2
        long long b = sum - s;       // a - b
        long long c = a / b;         // a + b

        int missing = (c - b) / 2;
        int repeating = (c + b) / 2;
        
        return {missing, repeating};
    }
};
