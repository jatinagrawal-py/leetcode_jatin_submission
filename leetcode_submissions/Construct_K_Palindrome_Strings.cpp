class Solution {
public:
    bool canConstruct(string s, int k) {
         int n = s.size();
    if (k > n) return false; // Can't create more substrings than the length of the string
    if (n == k) return true; // Each character can form a palindrome
    
    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }
    
    int oddCount = 0;
    for (auto& [ch, freq] : charCount) {
        if (freq % 2 != 0) oddCount++;
    }
    
    // Minimum palindromes needed is oddCount
    return oddCount <= k;
    }
};