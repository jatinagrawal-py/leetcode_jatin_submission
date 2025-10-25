class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int maxi = nums[k];
        int mini = nums[k];
        int n = nums.size();
        int j = k;
        int i = k;

        while(i>0 || j<n-1 ){
            int lefty = i<=0? 0:nums[i-1];
            int righty = j>=n-1?0:nums[j+1];

            if(lefty>righty){
                mini = min(lefty,mini);
                
                i--;
                maxi = max(maxi , mini*(j-i+1));
            }
            else{
                mini = min(righty,mini);
                
                j++;
                maxi = max(maxi , mini*(j-i+1));
            }
        }

        return maxi;
    }
};