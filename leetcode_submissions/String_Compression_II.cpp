int dp[101][27][101][101];
class Solution {
public:
    int solve(string & s , int k , int i , int prev_char , int freq){
        if(k<0)return INT_MAX;
        if(i>=s.size())return 0;
        if(dp[i][prev_char][freq][k]!=-1)return dp[i][prev_char][freq][k];

        int delete_i = solve(s,k-1,i+1,prev_char,freq);

        int keep_i;

        if(prev_char!=(s[i]-'a')){
            keep_i = 1+solve(s,k,i+1,s[i]-'a',1);
        }
        else{
            int add_one = 0;
            if(freq==1 || freq==9 || freq==99){
                add_one = 1;
            }
            keep_i = add_one + solve(s,k,i+1,prev_char,freq+1);
        }

        return dp[i][prev_char][freq][k]= min(keep_i,delete_i);
    }

    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s,k,0,26,0);
    }
};