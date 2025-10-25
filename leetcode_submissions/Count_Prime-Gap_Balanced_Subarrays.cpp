class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int U = *max_element(nums.begin(), nums.end());
        vector<bool> is_prime(U+1, true);
        if (U >= 0) is_prime[0] = false;
        if (U >= 1) is_prime[1] = false;
        for (int i = 2; i * i <= U; i++) if (is_prime[i])
            for (int j = i * i; j <= U; j += i)
                is_prime[j] = false;
        
        vector<int> pos, vals;
        pos.reserve(n);
        vals.reserve(n);
        for (int i = 0; i < n; i++) 
            if (nums[i] <= U && is_prime[nums[i]]) {
                pos.push_back(i);
                vals.push_back(nums[i]);
            }
        
        int P = pos.size();
        if (P < 2) return 0;
        
        vector<long long> rc(P), pref(P);
        for (int j = 0; j < P; j++) {
            int nxt = (j + 1 < P ? pos[j+1] : n);
            rc[j] = nxt - pos[j];
            pref[j] = rc[j] + (j ? pref[j-1] : 0);
        }
        
        long long ans = 0;
        deque<int> minDq, maxDq;
        int j = 0;
        
        for (int i = 0; i < P; i++) {
            while (j < P) {
                int v = vals[j];
                int curr_max = max(maxDq.empty() ? INT_MIN : vals[maxDq.front()], v);
                int curr_min = min(minDq.empty() ? INT_MAX : vals[minDq.front()], v);
                if (curr_max - curr_min <= k) {
                    while (!minDq.empty() && vals[minDq.back()] > v) minDq.pop_back();
                    minDq.push_back(j);
                    while (!maxDq.empty() && vals[maxDq.back()] < v) maxDq.pop_back();
                    maxDq.push_back(j);
                    j++;
                } else break;
            }
            int best = j - 1;
            if (best >= i + 1) {
                long long leftChoices = pos[i] - (i ? pos[i-1] : -1);
                long long sumRight = pref[best] - pref[i];
                ans += leftChoices * sumRight;
            }
            if (!minDq.empty() && minDq.front() == i) minDq.pop_front();
            if (!maxDq.empty() && maxDq.front() == i) maxDq.pop_front();
        }
        
        return ans;
    }
};