class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string ans = "";
        int count = 1;
        int j = 1;
        int n = s.size();
        while(j<n){
            while(j<n && count>0){
                ans+=s[j];
                if(s[j]=='(')count++;
                else count--;
                j++;
            }
            ans.pop_back();
            j = j+1;
            count++;
        }
        
        return ans;
    }
};