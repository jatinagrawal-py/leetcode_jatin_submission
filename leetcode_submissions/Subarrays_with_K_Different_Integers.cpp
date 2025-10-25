class Solution {
public:
    int solve(vector<int>& nums, int k){
        int i = 0;
        int j = 0;
        int count = 0;
        unordered_map<int,int>mpp;

        while(j<nums.size()){
            mpp[nums[j]]++;

            while(mpp.size()>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;}
            

            if(mpp.size()<=k){
                count+=(j-i+1);
            }
            j++;
        }

        return count;}
        
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};