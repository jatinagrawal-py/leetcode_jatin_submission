class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int mini = INT_MIN;

        for(auto it:mpp){
            mini = max(mini,it.second);
        }
        int count = 0;
        for(auto it:mpp){
            if(it.second==mini){
                count++;
            }
        }
        return count*mini;
    }
};