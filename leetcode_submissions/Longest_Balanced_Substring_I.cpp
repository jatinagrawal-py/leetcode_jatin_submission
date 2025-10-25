class Solution {
public:
    int longestBalanced(string s) {
        int ans = 1;
        int n = s.size();
        for(int i = 0;i<n;i++){
            vector<int>freq(26,0);
            for(int j = i;j<n;j++){
                freq[s[j]-'a']++;
                int common = -1;
                bool valid = true;
                for (int f : freq) {
                    if (f == 0) continue;
                    if (common == -1) common = f;
                    else if (common != f) { valid = false; break; }
                }
                if (valid) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};