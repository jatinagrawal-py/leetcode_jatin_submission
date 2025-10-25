class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<char> vow{'a','e','i','o','u','A','E','I','O','U'};

        int n = s.size();
        int c1 = 0;
        int c2 = 0;
        for(int i = 0;i<n/2;i++){
            for(auto it : vow){
                if(s[i]==it){
                    c1++;
                }
                if(s[n/2 + i]==it){
                    c2++;
                }
            }
        }
        if(c1==c2)return true;

        return false;
    }
};