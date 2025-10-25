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

    bool kmp(string &s , string&pattern , vector<int>&lps){
        int i = 0;
        int j = 0;

        while(i<s.size()){
            if(s[i]==pattern[j]){
                i++;
                j++;
            }
            if(j==pattern.size()){
                return true;
            }
            else if(pattern[j]!=s[i]){
                if(j!=0)j=lps[j-1];
                else{
                    i++;
                }
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        int lenb = b.size();
        int lena = a.size();

        int n = lenb/lena;
        int cnt = n;
        string ans = "";

        while(cnt--){
            ans+=a;
        }
        vector<int>lps(lenb,0);
        findlps(b,lps);
        if(kmp(ans,b,lps)){
            return n;
        }

        ans+=a;
        if(kmp(ans,b,lps))return n+1;

        ans+=a;
        if(kmp(ans,b,lps))return n+2;


        return -1;
    }
};