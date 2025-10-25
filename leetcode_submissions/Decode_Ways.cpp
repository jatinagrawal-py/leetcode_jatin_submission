class Solution {
public:
    int dp[101];
    int solve(string &s , int i){
        if(i>=s.size()){
            return 1;
        }

        if(s[i]=='0')return 0;

        if(dp[i]!=-1)return dp[i];

        int one = solve(s,i+1);

        int two = 0;

        if(i<s.size()-1){

            string twos = "";
            twos+=s[i];
            twos+=s[i+1];

            int towss = stoi(twos);

            if(towss<=26){
                two = solve(s,i+2);
            }
        }

        return dp[i]= one + two;
        
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};