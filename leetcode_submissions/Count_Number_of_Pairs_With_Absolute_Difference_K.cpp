class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans =0;
        for(int i =0 ;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if((nums[i]-nums[j]==k||nums[i]-nums[j]==(-1*k))&&i<j)
                {ans = ans +1;}
            }
        }
        return ans;
    }
};