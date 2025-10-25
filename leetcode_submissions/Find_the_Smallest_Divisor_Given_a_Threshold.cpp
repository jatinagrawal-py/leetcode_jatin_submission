class Solution {
public:
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        // Find the maximum:
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    long long summ(vector<int> &v, int hourly) {
        long long totalH = 0;  // Use long long to prevent overflow
        int n = v.size();
        // Calculate total hours:
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)(v[i]) / (double)(hourly));
        }
        return totalH;
    }


    int smallestDivisor(vector<int>& v, int t) {
        int low = 1, high = findMax(v);

        // Apply binary search:
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Prevent overflow
            long long su = summ(v, mid);
            if (su <= t) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};