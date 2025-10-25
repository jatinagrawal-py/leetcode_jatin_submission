class Solution {
public:
    string lexSmallest(string s) {
        string ans = s;
        int n = s.size();

        string temp = "";
        for (int k = 1; k <= n; k++) {
            temp = string(1, s[k - 1]) + temp;   
            ans = min(ans, temp + s.substr(k));
        }

        for (int k = 1; k <= n; k++) {
            string t = s;                        
            reverse(t.end() - k, t.end());       
            ans = min(ans, t); 
        }

        return ans;
    }
};
