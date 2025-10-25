class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]%3==0){
                ans = ans +0;
                continue;
            }
            else if(nums[i]==1){
                ans = ans +1;
                continue;
            }
            else if(nums[i]%3==1 || nums[i]%3==2){
                ans = ans +1;
                continue;
            }
            
        }
        return ans ;

    }
};