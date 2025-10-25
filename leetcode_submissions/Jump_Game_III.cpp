class Solution {
public:
    int dp[50001]; 

    bool solve(vector<int>& arr, int i){
        if(i < 0 || i >= arr.size()) return false;
        if(arr[i] == 0) return true;
        if(dp[i] != -1) return dp[i]; 
        
        dp[i] = 0; 

        bool plus  = solve(arr, i + arr[i]);
        bool minus = solve(arr, i - arr[i]);

        return dp[i] = (plus || minus);
    }

    bool canReach(vector<int>& arr, int start) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, start);
    }
};
