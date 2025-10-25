class Solution {
public:
    int dp[101][101];

    int solve(string &s , int l , int r){
        if(l==r)return 1;
        if(l>r)return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        int i = l+1;
        while(i<=r && s[i]==s[l]){
            i++;
        }

        int basic = 1+solve(s,i,r);
        int lalach = INT_MAX;

        for(int j = i+1; j<=r;j++){
            if(s[l]==s[j]){
                lalach = min(lalach , (solve(s,i,j-1)+solve(s,j,r)));
            }
        }

        return dp[l][r]= min(basic,lalach);

    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        return solve(s,0,n-1);
    }
};