class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long  sum = 0;
        for(auto it:nums){
            sum+=it;
        }

        int ans;
        int mini = INT_MAX;

        long long leftsum = 0;
        long long rightsum = sum;

        for(int i = 0;i<n;i++){
            leftsum+=nums[i];
            rightsum-=nums[i];
            if(i==n-1){
                int a = abs((leftsum/(i+1)) - 0 );
                if(a<mini){
                    ans = i;
                    mini = a;
                }
            }
            else{
                int a = abs((leftsum/(i+1)) - (rightsum/(n-i-1)) );
                if(a<mini){
                    ans = i;
                    mini = a;
                }
            }
        }

        return ans;
    }
};