class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        vector<int> validFreqs;
        for (int f : freq)
            if (f > 0)
                validFreqs.push_back(f);

       

        int minDel = INT_MAX;

        for (int i = 0; i < validFreqs.size(); i++) {
            int deletions = 0;
            int targetMin = validFreqs[i];
            int targetMax = targetMin + k;

            for (int f : validFreqs) {
                if (f < targetMin)
                    deletions += f; // delete all
                else if (f > targetMax)
                    deletions += f - targetMax;
            }

            minDel = min(minDel, deletions);
        }

        return minDel;
    }
};
