class Solution {
public:
    vector<pair<int,int>>baby = {{100,0},{75,25},{50,50},{25,75}};

    double solve(int a , int b,vector<vector<double>>& dp){
        if(a<=0 && b<=0)return 0.5;

        if(a<=0)return 1.0;

        if(b<=0)return 0.0;

        if(dp[a][b]!=-1) return dp[a][b];

        double p = 0.0;

        for(auto it:baby){
            int aserver = it.first;
            int bserver = it.second;

            p+=solve(a-aserver , b-bserver,dp);
        }

        return dp[a][b]= 0.25*(p);
    }

    double soupServings(int n) {
        if(n>=5000)return 1;
        vector<vector<double>> dp(5001, vector<double>(5001, -1.0));
        return solve(n,n,dp);
    }
};