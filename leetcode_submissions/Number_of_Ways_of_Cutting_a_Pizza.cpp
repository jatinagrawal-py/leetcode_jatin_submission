class Solution {
public:
    int mod = 1e9+7;
    int dp[51][51][10];
    int solve(int i , int j , int k , vector<vector<int>>&app , int m , int n){
        if(app[i][j]<k){
            return 0;
        }
        if(k==1){
            if(app[i][j]>=1){
                return 1;
            }
            return 0;
        }

        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int ans = 0;

        for(int h = i+1 ; h<m ; h++){
            int lower = app[h][j];
            int upper = app[i][j]-lower;

            if(lower>=k-1 && upper>=1){
                ans =( ans+ solve(h,j,k-1,app,m,n))%mod;
            }
        }

        for(int v = j+1 ; v<n ; v++){
            int right = app[i][v];
            int left = app[i][j]-right;

            if(right>=k-1 && left>=1){
                ans=(ans+ solve(i,v,k-1,app,m,n))%mod;
            }
        }

        return dp[i][j][k]  = ans;
    }
    int ways(vector<string>& pizza, int k) {
        memset(dp , -1 , sizeof(dp));
        int m = pizza.size();
        int n = pizza[0].size();

        vector<vector<int>>app(m,vector<int>(n,0));

        for(int i = m-1;i>=0;i--){
            for(int j = n-1 ; j>=0;j--){
                if(j<n-1)app[i][j] = app[i][j+1];
                for(int l = i;l<m;l++){
                    if(pizza[l][j]=='A'){
                        app[i][j]++;
                    }
                }
            }
        }

        return solve(0,0,k,app,m,n);
    }
};