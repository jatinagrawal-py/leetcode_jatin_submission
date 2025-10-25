class Solution {
public:
    unordered_map<string,int>dp;
    int solve(int k , int i , int jump , int cangoback){
        if(i>k+1)return 0;
        string key = to_string(i) + to_string(jump) + to_string(cangoback);
        if(dp.count(key))return dp[key];
        int res = 0;
        if(i==k)res++;

        if(cangoback && i>0){
            res+=solve(k,i-1,jump,0);
        }

        res+=solve(k,(i+(1<<jump)),jump+1,1);

        return dp[key]= res;
    }
    int waysToReachStair(int k) {
        return solve(k,1,0,1);
    }
};