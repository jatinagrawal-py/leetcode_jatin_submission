class Solution {
public:
    string mini = "";

    void solve(const string &target, int i, vector<int> count, string temp) {
        int n = target.size();
        if (i == n) {
            if (temp > target && (mini == "" || temp < mini)) mini = temp;
            return;
        }

        int curr = target[i] - 'a';

        if (count[curr] > 0) {
            vector<int> nextCount = count;
            nextCount[curr]--;
            solve(target, i + 1, nextCount, temp + target[i]);
        }

        for (char j = target[i] + 1; j <= 'z'; ++j) {
            int idx = j - 'a';
            if (count[idx] > 0) {
                string candidate = temp + j;
                vector<int> tempCount = count; 
                tempCount[idx]--;              

                for (int k = 0; k < 26; ++k) {
                    while (tempCount[k] > 0) {
                        candidate.push_back(char('a' + k));
                        tempCount[k]--;
                    }
                }

                if (candidate > target && (mini == "" || candidate < mini)) {
                    mini = candidate;
                }
            }
        }
    }

    string lexGreaterPermutation(string s, string target) {
        string mx = s;
        sort(mx.rbegin(), mx.rend());
        if (mx <= target) return "";

        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        mini = "";
        solve(target, 0, count, "");
        return mini;
    }
};