class Solution {
public:
    bool scoreBalance(string s) {
        int sum = 0;
        for(auto it:s){
            sum+=(it-'a'+1);
        }
        int newsum = 0;
        for(int i = 0;i<s.size();i++){
            newsum+=(s[i]-'a'+1);
            sum-=(s[i]-'a'+1);
            if(sum==newsum){
                return true;
            }
        }
        return false;
    }
};