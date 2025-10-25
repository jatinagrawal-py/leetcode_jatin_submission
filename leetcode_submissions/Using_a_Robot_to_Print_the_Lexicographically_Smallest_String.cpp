class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minSuffix(n);
        minSuffix[n-1] = s[n-1];

        for (int i = n - 2; i >= 0; --i) {
            minSuffix[i] = min(s[i], minSuffix[i + 1]);
        }

        string t = "", paper = "";
        for (int i = 0; i < n; ++i) {
            t.push_back(s[i]);
            while (!t.empty() && t.back() <= minSuffix[i + 1 < n ? i + 1 : n - 1]) {
                paper.push_back(t.back());
                t.pop_back();
            }
        }

        while (!t.empty()) {
            paper.push_back(t.back());
            t.pop_back();
        }

        return paper;
    }
};
