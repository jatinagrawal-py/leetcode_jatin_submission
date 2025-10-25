class Solution {
public:
    int dp[1001][2001];
    int solve(vector<vector<int>>& piles, int k , int i){
        if(k<=0 || i>=piles.size()){
            return 0;
        }

        if(dp[i][k]!=-1)return dp[i][k];

        int not_taken = solve(piles,k,i+1);

        int taken = 0;
        int sum = 0;
        for(int j = 0 ; j<min(k,(int)piles[i].size());j++){
            sum+=piles[i][j];
            taken = max(taken,sum + solve(piles,k-(j+1),i+1));
        }

        return dp[i][k]= max(taken,not_taken);

    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(piles,k,0);
    }
};