class Solution {
public:
    int dp[101][101][101];
    int solve(vector<int>& nums, int k, int op1, int op2,int i){
        if(i>=nums.size())return 0;
        if(dp[i][op1][op2]!=-1) return dp[i][op1][op2];

        int res = INT_MAX;
        if(op1>0){
            res = min(res,(nums[i]+1)/2 + solve(nums,k,op1-1,op2,i+1));
        }
        if(op2>0 && nums[i]>=k){
            res = min(res,(nums[i]-k)+ solve(nums,k,op1,op2-1,i+1));
        }
        if(op1>0 && op2>0){
            if((nums[i]+1)/2 >= k){
                res = min(res,((nums[i]+1)/2)-k + solve(nums,k,op1-1,op2-1,i+1));
            }
            if(nums[i]>=k){
                res = min(res, ((nums[i]-k)+1)/2 + solve(nums,k,op1-1,op2-1,i+1));
            }
        }
        res = min(res,nums[i]+solve(nums,k,op1,op2,i+1));

        return dp[i][op1][op2]= res;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        // ya toh phela lagao
        // dusra lagao
        // dono lagao iske bhi 2 ways
        // ya toh kuch mat karo mkc
        memset(dp,-1,sizeof(dp));
        return solve(nums,k,op1,op2,0);

    }
};