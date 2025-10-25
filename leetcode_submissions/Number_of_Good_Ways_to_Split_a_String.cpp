class Solution {
public:
    int numSplits(string s) {
        int count = 0;
        int n = s.size();
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(auto it:s){
            mp2[it]++;
        }

        for(int i = 0;i<n-1;i++){
            mp1[s[i]]++;
            mp2[s[i]]--;
            if(mp2[s[i]]==0)mp2.erase(s[i]);
            if(mp1.size()==mp2.size())count++;
        }

        return count;
    }
};