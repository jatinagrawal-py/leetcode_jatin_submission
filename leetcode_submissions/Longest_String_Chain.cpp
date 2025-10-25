class Solution {
public:
    bool isp(string s1, string s2) { // Corrected parameter order (predecessor first)
        if (s1.length() + 1 != s2.length()) return false;

        int i = 0, j = 0;
        while (i < s1.length() && j < s2.length()) {
            if (s1[i] == s2[j]) {
                i++;
            } else {
                if (j - i > 0) return false; // More than one insertion
            }
            j++;
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> t(n, 1);
        int ans = 1;

        // Sort words based on their length
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isp(words[j], words[i])) { // Correct order
                    t[i] = max(t[i], t[j] + 1);
                    ans = max(ans, t[i]);
                }
            }
        }
        return ans;
    }
};
