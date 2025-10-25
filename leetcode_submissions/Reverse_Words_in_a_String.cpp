class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        string word = "";
        int i = n-1;

        while(i>=0){
            if(s[i]!=' '){
                word = s[i] + word;
            }
            else{
                if(!word.empty()){
                    if(!ans.empty())ans+=' ';
                    ans+=word;
                    word.clear();
                }
            }
            i--;
        }
        if(!word.empty()){
                    if(!ans.empty())ans+=' ';
                    ans+=word;
                    word.clear();
                }

        return ans;
    }
};