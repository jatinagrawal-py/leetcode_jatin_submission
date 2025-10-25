class Solution {
public:
    bool checkfreq(int freq[]) {
        for (int i = 0; i < 3; i++) {
            if (freq[i] == 0) return false;
        }
        return true;
    }

    int numberOfSubstrings(string s) {
        int freq[3] = {0, 0, 0};
        int count = 0;
        int i = 0, j = 0;

        // Expanding window to first valid state
        while (j < s.size() && !checkfreq(freq)) {
            freq[s[j] - 'a']++;
            j++;
        }

        // If no valid window was found, return early
        if (!checkfreq(freq)) return 0;
        
        count += s.size() - j + 1;

        // Sliding window logic
        while (i < s.size()) {
            freq[s[i] - 'a']--; // Shrink from left
            i++;

            // Expand window again if it becomes invalid
            while (j < s.size() && !checkfreq(freq)) {
                freq[s[j] - 'a']++;
                j++;
            }

            if (checkfreq(freq)) {
                count += s.size() - j + 1;
            } else {
                break;
            }
        }

        return count;
    }
};
