class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftmax(n);
        vector<int>rightmax(n);

        leftmax[0]=0;

        for(int i = 1;i<n;i++){
            leftmax[i] = max(leftmax[i-1],nums[i-1]);
        }
        rightmax[n-1]=0;

        for(int i = n-2 ; i>=0 ;i--){
            rightmax[i] = max(rightmax[i+1],nums[i+1]);
        }

        long long ans = INT_MIN;

        for(int j =1 ;j<n-1;j++){
            ans = max(ans , (long long)(leftmax[j] - nums[j]) * (long long)rightmax[j]);
        }

        if(ans < 0)return 0;
        return ans;


    }
};