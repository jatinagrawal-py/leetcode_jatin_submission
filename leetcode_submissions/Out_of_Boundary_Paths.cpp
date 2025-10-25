class Solution {
public:
    int dp[51][51][51];
    int mod = 1e9+7;
    vector<pair<int,int>>dir = {{1,0},{0,1},{0,-1},{-1,0}};
    int solve(int m, int n, int move, int i, int j , vector<vector<int>>&vis){
        if(i<0 || j<0 || i>=m || j>=n)return 1;
        if(move==0){
            if(i<0 || j<0 || i>=m || j>=n)return 1;
            return 0;
        }

        if(dp[i][j][move]!=-1) return dp[i][j][move];

        vis[i][j]=1;
        int res = 0;

        for(auto it:dir){
            int newi = i+it.first;
            int newj = j+it.second;
            res = (res+solve(m,n,move-1,newi,newj,vis))%mod;
        }

        vis[i][j]=0;

        return dp[i][j][move]=res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>>vis(m,vector<int>(n,0));
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow,startColumn,vis);
    }
};