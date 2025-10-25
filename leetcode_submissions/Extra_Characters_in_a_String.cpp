class Solution {
public:
    int dp[51];
    int solve(string &s , unordered_set<string>&st , int i){
        if(i>=s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int res = INT_MAX;

        res = 1+solve(s,st,i+1);
        string hehe = "";
        for(int j = i;j<s.size();j++){
            hehe+=s[j];
            if(st.count(hehe)){
                res = min(res,solve(s,st,j+1));
            }
        }
        return dp[i]= res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,-1,sizeof(dp));
        unordered_set<string>st(dictionary.begin(),dictionary.end());
        return solve(s,st,0);
    }
};