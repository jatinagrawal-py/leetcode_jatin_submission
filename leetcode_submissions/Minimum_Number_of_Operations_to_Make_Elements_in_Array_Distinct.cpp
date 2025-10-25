class Solution {
public:
    bool check(unordered_map<int,int>&mpp){
        for(auto it:mpp){
            if(it.second>1){
                return false;
            }
        }
        return true;
    }

    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>mpp;

        for(auto it:nums){
            mpp[it]++;
        }

        int ans = 0;
        int i = 0;
        while(i<nums.size()){
            if(check(mpp))return ans;
            int j = 0;
            while(j<3 && i+j<nums.size()){
                mpp[nums[i+j]]--;
                j++;
            }
            i+=3;
            ans++;
            
        }

        return ans;
    }
};