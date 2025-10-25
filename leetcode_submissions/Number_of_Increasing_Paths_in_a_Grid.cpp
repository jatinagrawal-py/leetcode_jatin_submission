class Solution {
public:
    vector<pair<int,int>>dir = {{1,0},{0,-1},{0,1},{-1,0}};
    int dp[1001][1001];
    int mod = 1e9+7;

    int solve(int i , int j , vector<vector<int>>& grid , int m , int n){

        if(dp[i][j]!=-1)return dp[i][j];
        int res = 1;

        for(auto it:dir){
            int newi = i+it.first;
            int newj = j+it.second;

            if(newi<m && newj<n && newi>=0 && newj>=0 && grid[newi][newj]<grid[i][j]){
                res = (res+solve(newi,newj,grid,m,n))%mod;
            }
        }

        return dp[i][j] = res;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long count = 0;
        
        memset(dp,-1,sizeof(dp));

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                count = (count + solve(i,j , grid , m , n))%mod;
            }
        }

        return (int)count;
    }
};