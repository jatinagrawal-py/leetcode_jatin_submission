class Solution {
public:
    string normalizeVowels(string s) {
        for (auto &ch : s) {
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') {
                ch = '*';
            }
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordList, vector<string>& queries) {
        unordered_set<string> exact(wordList.begin(), wordList.end());
        unordered_map<string,string> caseInsensitive;
        unordered_map<string,string> vowelInsensitive;

        for (auto &w : wordList) {
            string lower = w;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (!caseInsensitive.count(lower)) caseInsensitive[lower] = w;

            string norm = normalizeVowels(lower);
            if (!vowelInsensitive.count(norm)) vowelInsensitive[norm] = w;
        }

        vector<string> ans;
        for (auto q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (caseInsensitive.count(lower)) {
                ans.push_back(caseInsensitive[lower]);
                continue;
            }

            string norm = normalizeVowels(lower);
            if (vowelInsensitive.count(norm)) {
                ans.push_back(vowelInsensitive[norm]);
                continue;
            }

            ans.push_back("");
        }
        return ans;
    }
};
