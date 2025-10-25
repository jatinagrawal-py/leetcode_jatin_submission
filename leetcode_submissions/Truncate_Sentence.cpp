class Solution {
public:
    string truncateSentence(string s, int k) {
        int tem = 0;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(int(s[i])==32){
                tem = tem +1;
                if(tem==k){
                    break;
                }
            }
            ans = ans + s[i];
        }
        return ans;
    }
};