class Solution {
public:
    int mod = 1e9+7;
    vector<pair<int,int>> dir = {
    {2, 1}, {2, -1},   // down-right, down-left
    {-2, 1}, {-2, -1}, // up-right, up-left
    {1, 2}, {1, -2},   // right-down, right-up
    {-1, 2}, {-1, -2}  // left-down, left-up
    };
    int dp[4][3][5001];
    int solve(vector<vector<int>>&arr , int n , int i , int j){
        if(i<0 || j<0 || j>=3 || i>=4)return 0;
        if(arr[i][j]==-1)return 0;
        if(n==0)return 1;
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        
        int res = 0;

        for(auto it:dir){
            res = (res+solve(arr,n-1,i+it.first,j+it.second))%mod;
        }

        return dp[i][j][n]=res;
    }
    int knightDialer(int n) {
        vector<vector<int>>arr = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};

        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<4;i++){
            for(int j = 0;j<3;j++){
                ans = (ans+solve(arr,n-1,i,j))%mod;
            }
        }

        return ans;
    }
};