class Solution {
public:
    string makeGood(string s) {
    string re = "";  // Acts like a stack

    for (char c : s) {
        if (!re.empty() && abs(re.back() - c) == 32) { 
            re.pop_back();  // Remove last character if it forms a case-insensitive pair
        } else {
            re.push_back(c);
        }
    }

    return re;
    }
};