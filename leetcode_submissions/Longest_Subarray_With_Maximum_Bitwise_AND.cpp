class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ele = *max_element(nums.begin(),nums.end());
        
        int count = 0;
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==ele){count++;
                maxi = max(maxi,count);
            }
            else count = 0;
        }
        return maxi;
    }
};