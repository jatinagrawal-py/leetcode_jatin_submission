class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if(n<2){
            return s;
        }
        int i = 0;
        int j = 0;
        string ans="";
        while(j<n){
            if(s[j]==' '){
                string temp = s.substr(i,j-i);
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=" ";
                j++;
                i=j;
            }
            j++;
        }
        if(j+1>=n){
            string temp = s.substr(i,j-i+1);
            reverse(temp.begin(),temp.end());
            ans+=temp;
        }
        return ans;
    }
};