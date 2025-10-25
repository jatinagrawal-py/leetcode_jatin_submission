class Solution {
public:
    string majorityFrequencyGroup(string s) {
        // freq -> char
        // grp size then freq dekhni hai
        vector<string>ans(101,"");

        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        for(auto it:mpp){
            ans[it.second].push_back(it.first);
        }

        int maxigrp = 0;
        for(auto it:ans){
            maxigrp = max(maxigrp,(int)it.size());
        }
        
        for(int i = 100;i>=1;i--){
            if(ans[i].size()==maxigrp)return ans[i];
        }

        return "";
    }
};