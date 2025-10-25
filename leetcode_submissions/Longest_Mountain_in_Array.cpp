class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        int len = 0;

        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int l = i, r = i;

                while (l > 0 && arr[l - 1] < arr[l]) {
                    l--;
                }

                while (r < n - 1 && arr[r + 1] < arr[r]) {
                    r++;
                }

                len = max(len, r - l + 1);
                i = r;
            }
        }

        return len;
    }
};
