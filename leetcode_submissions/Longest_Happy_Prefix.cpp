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
    string longestPrefix(string s) {
        vector<int>lps(s.size(),0);
        findlps(s,lps);
        
        return s.substr(0,lps[s.size()-1]);
    }
};