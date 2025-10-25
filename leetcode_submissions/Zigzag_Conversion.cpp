class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> hehe(numRows, "");
        int i = 0, dir = 1; // down niche jaoo baby

        for (char c : s) {
            hehe[i] += c;

            if (i == 0) dir = 1;                
            else if (i == numRows - 1) dir = -1;

            i += dir;
        }

        string ans;
        for (auto &row : hehe) ans += row;
        return ans;
    }
};
