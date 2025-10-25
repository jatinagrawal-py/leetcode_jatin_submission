class Solution {
public:
// abcb
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j<s.size()){
            mpp[s[j]]++;

            while(mpp.size()!=j-i+1){
                mpp[s[i]]--;
                if(mpp[s[i]]==0)mpp.erase(s[i]);
                i++;
            }

            if(mpp.size()==j-i+1){
                ans = max(ans,j-i+1);
            }

            j++;
        }

        return ans;
    }
};