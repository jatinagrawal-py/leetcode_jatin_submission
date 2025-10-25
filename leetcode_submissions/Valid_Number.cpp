class Solution {
private:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    string trim(const string &s) {
        int start = 0, end = s.size() - 1;
        while (start <= end && isspace(s[start])) start++;
        while (end >= start && isspace(s[end])) end--;
        if (start > end) return "";
        return s.substr(start, end - start + 1);
    }

public:
    bool isNumber(string s) {
        s = trim(s);
        if (s.empty()) return false;

        bool numberSeen = false;
        bool eSeen = false;
        bool decimalSeen = false;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (c == '.') {
                if (decimalSeen || eSeen) return false;
                decimalSeen = true;
            } 
            else if (c == 'e' || c == 'E') {
                if (eSeen || !numberSeen) return false;
                eSeen = true;
                numberSeen = false;  // reset for exponent part
            } 
            else if (c == '+' || c == '-') {
                if (i != 0 && s[i-1] != 'e' && s[i-1] != 'E') return false;
                numberSeen = false;  // need a digit after sign
            } 
            else {
                if (!isDigit(c)) return false;
                numberSeen = true;
            }
        }

        return numberSeen;
    }
};
