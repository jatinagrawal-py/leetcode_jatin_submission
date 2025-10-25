class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                count++;
            }
            else{
                if(count%2==1)return false;
                else{
                    count=1;
                }
            }
        }
        return true;
    }
};