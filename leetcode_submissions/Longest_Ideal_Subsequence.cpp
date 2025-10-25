class Solution {
public:
    int dp[100001][27];
    int solve(string &s , int k , int i , int diff){
        if(i>=s.size())return 0;
        
        if(dp[i][diff+1]!=-1) return dp[i][diff+1];
        int idx = s[i]-'a';

        int nottake = solve(s,k,i+1,diff);

        int take = INT_MIN;

        if(diff==-1 || abs(diff-idx)<=k){
            take = solve(s,k,i+1,idx)+1;
        }

        return dp[i][diff+1]=max(nottake , take);
    }
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s,k,0,-1);
    }
};