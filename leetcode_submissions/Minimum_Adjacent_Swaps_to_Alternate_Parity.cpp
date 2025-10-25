class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        for(int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                pos.push_back(i);
        }
        int m = pos.size(), o = n - m;
        if (abs(m - o) > 1) return -1;

        auto calc = [&](bool startEven) {
            vector<int> tgt;
            for(int i = 0; i < n; i++) {
                if ((i % 2 == 0) == startEven)
                    tgt.push_back(i);
            }
            long long cost = 0;
            for(int i = 0; i < m; i++) {
                cost += llabs((long long)pos[i] - tgt[i]);
            }
            return cost;
        };

        if (n % 2 == 0)
            return min(calc(true), calc(false));
        return calc(m > o);
    }
};
