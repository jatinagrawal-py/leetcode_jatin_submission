class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans = 0;
        long long i = 1;
        int j = columnTitle.size() - 1;

        while (j >= 0) {
            int val = columnTitle[j] - 'A' + 1;
            ans += val * i;
            i *= 26;
            j--;
        }
        return (int)ans;
    }
};
