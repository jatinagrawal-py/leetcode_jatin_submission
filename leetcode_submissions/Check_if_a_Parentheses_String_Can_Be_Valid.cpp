class Solution {
public:
    bool canBeValid(string s, string locked) {
         int n = s.length();
    if (n % 2 != 0) return false; // A valid parentheses string must have an even length.
    
    int openBalance = 0, closeBalance = 0;
    
    // Left-to-right pass
    for (int i = 0; i < n; ++i) {
        if (locked[i] == '0' || s[i] == '(') {
            openBalance++;
        } else {
            openBalance--;
        }
        if (openBalance < 0) return false; // Too many ')' in the left-to-right pass.
    }
    
    // Right-to-left pass
    for (int i = n - 1; i >= 0; --i) {
        if (locked[i] == '0' || s[i] == ')') {
            closeBalance++;
        } else {
            closeBalance--;
        }
        if (closeBalance < 0) return false; // Too many '(' in the right-to-left pass.
    }
    
    return true;
        }
    
};