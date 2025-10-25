class Solution {
public:

    void findlps(string &pattern , vector<int>&lps){
        int i = 1;
        int len = 0;
        while(i<pattern.size()){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        
    }

    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        string temp = s + "-" + rev;

        vector<int>lps(temp.size(),0);
        findlps(temp,lps);

        int len = lps[temp.size()-1];

        return rev.substr(0,s.size()-len) + s;
        
    }
};