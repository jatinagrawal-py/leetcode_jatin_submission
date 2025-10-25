class Solution {
public:
    int countHomogenous(string s) {
        int count = 0;
        int n = s.size();
        int mod = 1e9+7;
        unordered_map<int,int>mpp;
        int i = 0;
        int j = 0;
        while(j<n){
            mpp[s[j]]++;
            while(mpp.size()>1){
                mpp[s[i]]--;
                if(mpp[s[i]]==0)mpp.erase(s[i]);
                i++;
            }
            if(mpp.size()==1){
                int si = j-i+1;
                count = (count + si)%mod;
            }
            j++;
        }
        return count;
    }
};