class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";

        bool t[1001][1001] = {false};

        for(int l = 1;l<=s.size();l++){
            for(int i = 0;i+l-1<s.size();i++){
                int j = i + l-1;
                if(i==j){
                    t[i][j]=true;
                    
                }
                else if(i+1==j){
                    if(s[i]==s[j])t[i][j]=true;
                    
                }
                else{
                    if(s[i]==s[j] && t[i+1][j-1])t[i][j]=true;
                }

                if(t[i][j]==true){
                    ans = s.substr(i,l);
                }
            }
        }


        return ans;
    }
};