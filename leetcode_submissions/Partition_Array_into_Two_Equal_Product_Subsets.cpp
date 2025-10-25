class Solution {
public:
    bool solve(vector<int>& nums  , long double l , long double r , int i){
        if(i>=nums.size()){
            if(l==r && 1==l){
                return true;
            }

            return false;
        }

        bool lh = solve(nums,l/nums[i],r,i+1);
        bool rh = solve(nums,l,r/nums[i],i+1);


        return lh||rh;
        
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return solve(nums,target,target,0);
    }
};