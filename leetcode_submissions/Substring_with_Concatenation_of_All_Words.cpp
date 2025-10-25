class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wordLen = words[0].size();
        int totalLen = wordLen * words.size();
        if (s.size() < totalLen) return ans;

        unordered_map<string,int> wordCount;
        for (auto &w : words) wordCount[w]++;

        for (int shift = 0; shift < wordLen; shift++) {
            int left = shift, count = 0;
            unordered_map<string,int> window;

            for (int right = shift; right + wordLen <= s.size(); right += wordLen) {
                string w = s.substr(right, wordLen);
                
                if (wordCount.find(w) != wordCount.end()) {
                    window[w]++;
                    count++;

                    while (window[w] > wordCount[w]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == words.size()) {
                        ans.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return ans;
    }
};
