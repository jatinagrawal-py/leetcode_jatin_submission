#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> maskIndex;
        maskIndex[0] = -1;  // Base case for when the mask is zero (all vowels even)
        int mask = 0;       // Mask to track the parity of vowels
        int maxLength = 0;

        for (int i = 0; i < s.size(); i++) {
            // Flip bits based on the vowel encountered
            if (s[i] == 'a') mask ^= (1 << 0);
            else if (s[i] == 'e') mask ^= (1 << 1);
            else if (s[i] == 'i') mask ^= (1 << 2);
            else if (s[i] == 'o') mask ^= (1 << 3);
            else if (s[i] == 'u') mask ^= (1 << 4);

            // If the current mask has been seen before, calculate the substring length
            if (maskIndex.find(mask) != maskIndex.end()) {
                maxLength = max(maxLength, i - maskIndex[mask]);
            } else {
                maskIndex[mask] = i;  // Store the first occurrence of this mask
            }
        }

        return maxLength;
    }
};
