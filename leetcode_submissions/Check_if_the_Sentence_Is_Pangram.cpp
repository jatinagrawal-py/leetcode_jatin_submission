class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>freq(26,1);
        for(auto it:sentence){
            freq[it-'a']--;
        }

        for(auto it:freq){
            if(it>0)return false;
        }

        return true;
    }
};