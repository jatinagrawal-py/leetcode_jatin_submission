class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            int mask = 0;
            for(int j = i;j<nums.size();j++){
                if((mask&nums[j])!=0)break;
                else{
                    mask = mask|nums[j];
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
        
    }
};