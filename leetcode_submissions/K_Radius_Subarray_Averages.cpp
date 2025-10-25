class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // 2k+1 elements
        vector<int>ans(nums.size(),-1);
        long long sum = 0;

        int i = 0;
        int j = 0;
        while(j<nums.size()){
            sum+=nums[j];
            
            if(j-i+1 == 2*k + 1  ){
                int avg = sum/(2*k+1);
                ans[j-k] = avg;
                sum-=nums[i];
                i++;
            }

            j++;
        }

        
        return ans;
    }
};