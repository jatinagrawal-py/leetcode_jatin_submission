class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        unordered_map<int,int>mpp;
        int res=0;
        mpp[0]=1;

        for(auto it:nums){
            sum+=it;
            int diff = sum - goal;
            

            if(mpp.find(diff)!=mpp.end()){
                res+=mpp[diff];
            }

            mpp[sum]++;

        }

        return res;
    }
};