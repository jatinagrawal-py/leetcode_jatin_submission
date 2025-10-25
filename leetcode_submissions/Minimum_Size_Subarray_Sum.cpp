class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int count = INT_MAX;
        int n = nums.size();
        int j = 0,i=0;
        int sum = 0;
        while(j<n){
            sum+=nums[j];

            while(sum>=target){
                count = min((j-i+1),count);
                sum-=nums[i];
                i++;
            }

            j++;
        }
        if(count==INT_MAX)return 0;
        return count;
    }
};