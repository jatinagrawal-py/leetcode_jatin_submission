class Solution {
public:
    int calculate(string s) {
        long long curr = 0, last = 0, res = 0;
        char op = '+';
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) curr = curr * 10 + (c - '0');
            if ((!isdigit(c) && c != ' ') || i == n - 1) {
                if (op == '+') { res += last; last = curr; }
                else if (op == '-') { res += last; last = -curr; }
                else if (op == '*') last *= curr;
                else if (op == '/') last /= curr;
                op = c;
                curr = 0;
            }
        }
        res += last;
        return res;
    }
};
