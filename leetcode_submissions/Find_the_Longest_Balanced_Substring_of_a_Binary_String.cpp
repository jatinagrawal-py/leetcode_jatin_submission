class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        // if encountered 0 then count = 0 and count++;
        int ans = 0;
        int i = 0;
        int n = s.size();
        while(i<n){
            int count = 0;
            while(i<n && s[i]=='0'){
                count++;
                i++;
            }
            int si = count;
            while(i<n && s[i]=='1'){
                count--;
                i++;
            }
            count = max(0,count);
            ans = max(ans,(si-count)*2);
        }
        return ans;
    }
};