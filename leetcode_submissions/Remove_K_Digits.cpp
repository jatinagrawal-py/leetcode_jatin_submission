class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n == k) return "0";

        stack<char> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

    
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

      
        int idx = 0;
        while (idx < ans.size() && ans[idx] == '0') idx++;

        ans = ans.substr(idx);
        return ans.empty() ? "0" : ans;
    }
};
