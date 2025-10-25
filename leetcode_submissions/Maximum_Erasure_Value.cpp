class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        int i = 0;
        int j = 0;
        int maxi = INT_MIN;
        unordered_map<int,int>mpp;
        while(j<nums.size()){
            sum+=nums[j];
            mpp[nums[j]]++;

            while(mpp.size()<(j-i+1)){
                mpp[nums[i]]--;
                sum-=nums[i];
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
            }

            if(mpp.size()==(j-i+1)){
                maxi = max(maxi,sum);
            }
            j++;
        }

        return maxi;
    }
};