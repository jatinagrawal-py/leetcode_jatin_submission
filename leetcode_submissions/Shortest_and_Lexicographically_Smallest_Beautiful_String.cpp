class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0, j = 0, count = 0;
        int minLen = INT_MAX;
        string result = "";

        while (j < n) {
            if (s[j] == '1') count++;

            while (count > k) {
                if (s[i] == '1') count--;
                i++;
            }

            while (count == k && s[i] == '0') {
                i++;
            }

            if (count == k) {
                int len = j - i + 1;
                string temp = s.substr(i, len);
                if (len < minLen || (len == minLen && temp < result)) {
                    minLen = len;
                    result = temp;
                }
            }

            j++;
        }

        return result;
    }
};
