class Solution {
public:
    vector<string> ans;

    void solve(string &s, unordered_set<string>& st, string path, int index) {
        if (index == s.size()) {
            path.pop_back(); 
            ans.push_back(path);
            return;
        }

        string temp = "";
        for (int j = index; j < s.size(); ++j) {
            temp += s[j];
            if (st.find(temp) != st.end()) {
                solve(s, st, path + temp + " ", j + 1);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        solve(s, st, "", 0);
        return ans;
    }
};
