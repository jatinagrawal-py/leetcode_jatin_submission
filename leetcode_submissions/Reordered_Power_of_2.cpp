class Solution {
public:
    bool solve(multiset<char>& st, int num) {
        if (st.empty()) {
            return (num & (num - 1)) == 0; 
        }

        for (char c = '0'; c <= '9'; c++) {
            if (num == 0 && c == '0') continue;
            auto it = st.find(c);
            if (it != st.end()) {
                st.erase(it); 
                if (solve(st, num * 10 + (c - '0'))) return true;
                st.insert(c); 
            }
        }

        return false;
    }

    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        multiset<char> st(s.begin(), s.end());
        return solve(st, 0);
    }
};
