class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int i = 0;
        while(i<=farthest){
            farthest = max(farthest,i+nums[i]);
            if(farthest>=nums.size()-1)return true;
            i++;
        }
        
        return false;

    }
};