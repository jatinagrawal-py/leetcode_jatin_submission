class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto ot:nums){
            mpp[ot]++;
        }

        int dis = mpp.size();
        int count = 0;
        int i = 0;
        int j = 0;
        mpp.clear();
        int n = nums.size();

        while(j<nums.size()){
            mpp[nums[j]]++;

            while(mpp.size()==dis && i<=j){
                count+=(n-j);
                mpp[nums[i]]--;
                if(mpp[nums[i]]<=0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }

        return count;
    }
};