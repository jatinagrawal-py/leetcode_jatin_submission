class Solution {
public:
    string convertToTitle(int num) {
        string ans = "";
        while (num > 0) {
            num--;
            int rem = num % 26;
            ans += ('A' + rem);
            num /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
