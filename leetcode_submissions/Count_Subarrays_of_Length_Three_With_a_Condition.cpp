class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        // 2*(x1 + x3) = *x2;
        int n  =nums.size();
        if(n<3){
            return 0;
        }
        
        int i  =0;
        int j  =2;
        int ans  =0;
        while(j<n){
            if((2*(nums[i]+nums[j]))==nums[i+1]){
                ans++;
            }
            i++;
            j++;
        }

        return ans;

    }
};