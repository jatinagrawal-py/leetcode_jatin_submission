class Solution {
public:
    int dp[2][101][101];
    int solve(vector<int>& piles , int person , int i , int m){
        if(i>=piles.size())return 0;
        if(dp[person][i][m]!=-1) return dp[person][i][m];
        int res = person==1? -1 : INT_MAX;
        int n = piles.size();
        if(person ==1){
            int sum = 0;
            for(int x = 1;x<=min(2*m , n-i);x++){
                sum+=piles[i-1+x];
                res = max(res,sum+solve(piles,0,x+i,max(x,m)));
            }
        }
        else{
            for(int x = 1;x<=min(2*m , n-i);x++){
                res = min(res,solve(piles,1,x+i,max(m,x)));
            }
        }

        return dp[person][i][m]= res;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solve(piles,1,0,1);
    }
};