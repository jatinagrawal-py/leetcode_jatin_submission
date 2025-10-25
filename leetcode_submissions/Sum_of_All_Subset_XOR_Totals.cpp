class Solution {
public:
    int solve(vector<int>& nums,int i , int x){
        if(i>=nums.size()){
            return x;
        }

        int include = solve(nums,i+1,nums[i]^x);
        int exclude = solve(nums,i+1,x);

        return include+exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        // subset hai its like empty se leke sare combo means sare combo
        // phele 1 liya phir 2 element ko comine karke loop chalaya phir 3 element ko combine kia aisa kuch hai 
        return solve(nums,0,0);
    }
};