class Solution {
public:
    int minOperations(string s) {
        vector<int>freq(26,0);
        for(auto it:s){
            freq[it-'a']++;
        }

        int idx = -1;

        for(int i = 1;i<26;i++){
            if(freq[i]>0){
                idx = i;
                break;
            }
        }

        if(idx==-1)return 0;

        return 26-idx;
    }
};