class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int,int>mpp;
        // mpp[nums[0]]=0;
        // for(int i = 1;i<nums.size();i++){
        //     int rem = target-nums[i];
        //     if(mpp.count(rem)){
        //         return {mpp[rem],i};
        //     }
        //     mpp[nums[i]]=i;
        // }

        // return {};

        vector<pair<int,int>>newar;
        for(int i = 0;i<nums.size();i++){
            newar.push_back({nums[i],i});
        }
        sort(newar.begin(),newar.end());
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int sum = newar[l].first+newar[r].first;
            if(sum==target){
                return {newar[l].second,newar[r].second};
            }
            else if(sum<target){
                l++;
            }
            else r--;
        }

        return {};
    }
};