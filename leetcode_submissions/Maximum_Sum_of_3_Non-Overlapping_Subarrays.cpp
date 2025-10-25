class Solution {
public:
    int dp[4][20001];
    int helper(vector<int>&subarray , int k , int count , int i , vector<int>&ans){
        if(count==0)return 0;
        if(i>=subarray.size())return INT_MIN;
        if(dp[count][i]!=-1) return dp[count][i];

        int take_i = subarray[i] + helper(subarray,k,count-1,i+k,ans);
        int nottake_i = helper(subarray,k,count,i+1,ans);

        return dp[count][i]= max(take_i , nottake_i);

    }
    void solve(vector<int>&subarray , int k , int count , int i , vector<int>&ans){
        if(count==0)return;
        if(i>=subarray.size())return;

        int take_i = subarray[i] + helper(subarray,k,count-1,i+k,ans);
        int nottake_i = helper(subarray,k,count,i+1,ans);

        if(take_i>=nottake_i){
            ans.push_back(i);
            solve(subarray,k,count-1,i+k,ans);
        }
        else{
           solve(subarray,k,count,i+1,ans); 
        }
        return;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int>subarray;
        int j = 0;
        memset(dp,-1,sizeof(dp));
        int i = 0;
        int sum = 0;
        while(j<nums.size()){
            sum+=nums[j];
            while(j-i+1>k){
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k){
                subarray.push_back(sum);
            }
            j++;
        }
        vector<int>ans;
        solve(subarray , k, 3 , 0, ans);
        return ans;
    }
};