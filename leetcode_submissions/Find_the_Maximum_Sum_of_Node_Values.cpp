class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& e) {
        long long sum = 0;
        vector<long long> gains;

        for (int x : nums) {
            long long xor_val = x ^ k;
            sum += x;
            gains.push_back(xor_val - x);
        }

        sort(gains.rbegin(), gains.rend());

        long long totalGain = 0;
        int count = 0;

        for (long long g : gains) {
            if (g > 0) {
                totalGain += g;
                count++;
            }
        }

        if (count % 2 == 0) {
            return sum + totalGain;
        } else {
            long long min_diff = LLONG_MAX;

            for (long long g : gains) {
                min_diff = min(min_diff, abs(g));
            }

            return sum + totalGain - min_diff;
        }
    }
};
