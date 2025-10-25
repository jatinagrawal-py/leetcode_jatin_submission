class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Step 1: Calculate the max frequency requirement for words2
    vector<int> maxFreq(26, 0); // For 26 lowercase letters
    for (const string& word : words2) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            maxFreq[i] = max(maxFreq[i], freq[i]);
        }
    }

    // Step 2: Check each word in words1 against maxFreq
    vector<string> result;
    for (const string& word : words1) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }

        bool isUniversal = true;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] < maxFreq[i]) {
                isUniversal = false;
                break;
            }
        }
        if (isUniversal) {
            result.push_back(word);
        }
    }

    return result;
    }
};