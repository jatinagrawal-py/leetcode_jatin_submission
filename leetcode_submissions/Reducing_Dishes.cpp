class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& s , int i , int t){
        if(i>=s.size()){
            return  0;
        }
        if(dp[i][t]!=-1)return dp[i][t];
        int take = s[i]*t + solve(s,i+1,t+1);
        int skip = solve(s,i+1,t);

        return dp[i][t]=max(take , skip);
    }
    int maxSatisfaction(vector<int>& s) {
        memset(dp,-1,sizeof(dp));
        sort(s.begin(),s.end());
        return solve(s,0,1);
    }
};