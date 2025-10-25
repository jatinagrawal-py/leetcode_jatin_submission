class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum = 0;
        int count=0;

        for(auto it:nums){
            sum+=it;
            int diff = sum-k;
            if(mp.find(diff)!=mp.end()){
                count+=mp[diff];
            }
            mp[sum]++;
        }
        return count;
    }
};