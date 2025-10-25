class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int n = pref.size();
        for(auto it:words){
            if(pref == it.substr(0,n))ans++;
        }
        return ans;
    }
};