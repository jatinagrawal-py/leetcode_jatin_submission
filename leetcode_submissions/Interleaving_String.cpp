class Solution {
public:
    int dp[101][101];
    bool solve(string &s1, string &s2, string &s3 , int i , int j){
        if(i>=s1.size() && j>=s2.size() && (i+j)>=s3.size())return true;
        if((i+j)>=s3.size()) return false;

        if(dp[i][j]!=-1) return dp[i][j];

        bool res = false;

        if(s1[i]==s3[i+j]){
            res = res|| solve(s1,s2,s3,i+1,j);
        }

        if(s2[j]==s3[i+j]){
            res = res|| solve(s1,s2,s3,i,j+1);
        }

        return dp[i][j]= res;

    }
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.size()+s2.size())!=s3.size())return false;
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s3,0,0); // k = i+j
    }
};