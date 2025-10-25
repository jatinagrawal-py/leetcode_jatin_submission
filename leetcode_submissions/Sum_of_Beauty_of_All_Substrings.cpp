class Solution {
public:
    int freq(int i, int j, string &s) {
        int arr[26] = {0};  

        for (int k = i; k <= j; k++) {
            arr[s[k] - 'a']++;
        }

        int maxi = *max_element(arr, arr + 26);

        // Find the smallest non-zero frequency
        int mini = INT_MAX;
        for (int x : arr) {
            if (x > 0) mini = min(mini, x);
        }

        return maxi - mini;
    }

    int beautySum(string s) {
        int n = s.length();
        if (n < 3) return 0;

        int sum = 0;
        for (int i = 0; i < n - 2; i++) {  // `i` starts from 0
            for (int j = i + 2; j < n; j++) {  // `j` should be `i + 2`
                int temp = freq(i, j, s);
                sum += temp;
            }
        }
        return sum;
    }
};