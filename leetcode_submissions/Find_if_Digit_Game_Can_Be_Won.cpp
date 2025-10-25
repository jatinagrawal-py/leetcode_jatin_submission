class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int sum1=0;
        int sum2=0;
        for(int i =0;i<n;i++){
            if(nums[i] < 10){
                sum1 = sum1 + nums[i];
            }
            else{
                sum2=sum2+nums[i];
            }
        }
        if(sum1==sum2){
            return false;
        }
        return true;
    }
};