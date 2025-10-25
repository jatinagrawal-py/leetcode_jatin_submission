class Solution {
public:
    vector<vector<int>>dir = {{1,1},{1,-1},{-1,-1},{-1,1}};
    int dp[501][501][2][2][5];

   int solve(vector<vector<int>>& grid , int n , int m ,
          int i, int j , bool canTurn , bool expectTwo , int dirIdx){
    
    if(dp[i][j][canTurn][expectTwo][dirIdx+1]!=-1) return dp[i][j][canTurn][expectTwo][dirIdx+1];
    int res = 0;

    if(dirIdx != -1){
        int ni = i + dir[dirIdx][0];
        int nj = j + dir[dirIdx][1];
        if(ni>=0 && nj>=0 && ni<n && nj<m){
            if(expectTwo && grid[ni][nj]==2){
                res = max(res,1+solve(grid,n,m,ni,nj,canTurn,false,dirIdx));
            }
            if(!expectTwo && grid[ni][nj]==0){
                res = max(res,1+solve(grid,n,m,ni,nj,canTurn,true,dirIdx));
            }
        }
    }

    if(canTurn && dirIdx != -1){
        int nd = (dirIdx + 1) % 4; 
        int ni = i + dir[nd][0];
        int nj = j + dir[nd][1];
        if(ni>=0 && nj>=0 && ni<n && nj<m){
            if(expectTwo && grid[ni][nj]==2){
                res = max(res,1+solve(grid,n,m,ni,nj,false,false,nd));
            }
            if(!expectTwo && grid[ni][nj]==0){
                res = max(res,1+solve(grid,n,m,ni,nj,false,true,nd));
            }
        }
    }

    if(dirIdx == -1){
        for(int d=0; d<4; d++){
            int ni = i + dir[d][0];
            int nj = j + dir[d][1];
            if(ni>=0 && nj>=0 && ni<n && nj<m){
                if(expectTwo && grid[ni][nj]==2){
                    res = max(res,1+solve(grid,n,m,ni,nj,canTurn,false,d));
                }
                if(!expectTwo && grid[ni][nj]==0){
                    res = max(res,1+solve(grid,n,m,ni,nj,canTurn,true,d));
                }
            }
        }
    }

    return dp[i][j][canTurn][expectTwo][dirIdx+1] = res;
}


    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        memset(dp,-1,sizeof(dp));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1){
                    res = max(res, 1+solve(grid,n,m,i,j,true,true,-1));
                }
            }
        }
        return res;
    }
};