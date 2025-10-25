class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k!=0)return false;

        int numberofgrp = n/k;

        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int maxi = 0;
        for(auto it:mpp){
            maxi = max(maxi,it.second);
        }

        if(numberofgrp>=maxi)return true;

        return false;
    }
};