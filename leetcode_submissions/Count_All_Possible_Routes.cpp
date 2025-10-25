class Solution {
public:
    int mod = 1e9+7;
    int dp[101][201];
    
    int solve(vector<int>& locations, int start, int finish, int fuel , int i){
        
        if(dp[i][fuel]!=-1)return dp[i][fuel];

        int res = i==finish?1:0;

        for(int k = i+1;k<locations.size();k++){
            if(fuel>=abs(locations[i]-locations[k])){
                res = (res+solve(locations,start,finish,fuel-abs(locations[i]-locations[k]),k))%mod;
            }
        }

        for(int k = i-1; k>=0;k--){
            if(fuel>=abs(locations[i]-locations[k])){
                res = (res+solve(locations,start,finish,fuel-abs(locations[i]-locations[k]),k))%mod;
            }
        }

        return dp[i][fuel]= res;

    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        return solve(locations,start,finish,fuel,start);
    }
};