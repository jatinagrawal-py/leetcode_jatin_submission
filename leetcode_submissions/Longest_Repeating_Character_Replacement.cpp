class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfreq = 0;
        int i = 0;
        int j = 0;
        unordered_map<char,int>mpp;

        int ans = 0;

        while(j<s.size()){
            mpp[s[j]]++;
            maxfreq = max(maxfreq,mpp[s[j]]);

            while((j-i+1)-maxfreq > k){
                mpp[s[i]]--;
                i++;
            }

            if((j-i+1)-maxfreq <= k){
                ans = max(ans,(j-i+1));
            }

            j++;
        }

        return ans;
    }
};