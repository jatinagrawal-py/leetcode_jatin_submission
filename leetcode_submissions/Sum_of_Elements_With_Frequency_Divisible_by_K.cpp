class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto it:nums)mpp[it]++;
        int sum = 0;
        for(auto it:mpp){
            if(it.second%k==0){
                sum+=(it.first*it.second);
            }
        }
        return sum;
    }
};