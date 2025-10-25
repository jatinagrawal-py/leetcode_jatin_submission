class Solution {
public:
    long long dp[100001];
    long long solve(unordered_map<int,int>&mpp , vector<int>&arr , int i){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        long long res = INT_MIN;
        res = max(res,solve(mpp,arr,i+1));
        long long temp = (long long)mpp[arr[i]]*arr[i];
        int newidx = upper_bound(arr.begin(),arr.end(),arr[i]+2)-arr.begin();
        res = max(res,solve(mpp,arr,newidx)+temp);

        return dp[i]= res;
    }
    long long maximumTotalDamage(vector<int>& power) {
        // same toh kar hi sakta hai bhosdiwala
        memset(dp,-1,sizeof(dp));
        unordered_map<int,int>mpp;
        for(auto it:power){
            mpp[it]++;
        }
        vector<int>arr;
        for(auto it:mpp){
            arr.push_back(it.first);
        }
        sort(arr.begin(),arr.end());
        return solve(mpp,arr,0);
    }
};