class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> hehe(k, 0);
        for (auto it : arr) {
            int rem = ((it % k) + k) % k;  // Normalize remainder
            hehe[rem]++;
        }

        if (hehe[0] % 2 != 0) return false;

        for (int i = 1; i < k; i++) {
            if (i == k - i) {
                if (hehe[i] % 2 != 0) return false;
            } else if (hehe[i] != hehe[k - i]) {
                return false;
            }
        }

        return true;
    }
};
