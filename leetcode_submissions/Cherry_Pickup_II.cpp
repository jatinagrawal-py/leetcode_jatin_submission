class Solution {
public:
    int dp[71][71][71];
    int solve(vector<vector<int>>& grid , int i , int j1 , int j2 , int r , int c){
        if(j1<0 || j2<0 || j1>=c || j2>=c)return -1e8;
        if(i==r-1){
            if(j1==j2)return grid[i][j1];
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int maxi = INT_MIN;

        for(int dj1 = -1; dj1<=1 ;dj1++){
            for(int dj2 = -1 ; dj2<=1 ; dj2++){
                if(j1==j2){
                    maxi = max(maxi,solve(grid,i+1,dj1+j1,dj2+j2,r,c)+grid[i][j1]);
                }
                else{
                    maxi = max(maxi,solve(grid,i+1,dj1+j1,dj2+j2,r,c)+grid[i][j1]+grid[i][j2]);
                }
            }
        }

        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));

        int n = grid.size();
        int m = grid[0].size();
        return solve(grid,0,0,m-1 , n , m);
    }
};