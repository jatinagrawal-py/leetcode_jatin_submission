class Solution {
public:
    int dp[301][11];
    int solve(vector<int>& jd, int d,int i){
        if(d==1){
            int maxi = jd[i];
            for(int idx = i;idx<jd.size();idx++){
                maxi = max(maxi,jd[idx]);
            }

            return maxi;
        }

        if(dp[i][d]!=-1)return dp[i][d];

        int finalres = INT_MAX;
        int maxi = jd[i];
        for(int idx = i ;idx<=jd.size()-d;idx++){
            maxi = max(maxi,jd[idx]);
            finalres = min(finalres,maxi+solve(jd,d-1,idx+1));
        }

        return dp[i][d]= finalres;
    }
    int minDifficulty(vector<int>& jd, int d) {
        memset(dp,-1,sizeof(dp));
        int n = jd.size();
        if(n<d)return -1;

        return solve(jd,d,0);
    }
};