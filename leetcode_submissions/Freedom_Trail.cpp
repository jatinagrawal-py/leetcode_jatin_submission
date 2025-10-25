class Solution {
public:
    int dp[101][101];
    int solve(string &ring, string &key, int i , int j){
        if(j>=key.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(ring[i]==key[j]){
            return 1+solve(ring,key,i,j+1);
        }
        int n = ring.size();
        
        int pichesteps = 0;
        int agesteps = 0;
        int ageidx;
        int picheidx;

        for(int k = i;k<i+n;k++){
            int hehe = k;
            hehe%=n;
            if(ring[hehe]==key[j]){
                ageidx=hehe;
                break;
            }
            agesteps++;
        }

        for(int k = i;k>i-n;k--){
            int hehe = k;
            if(hehe<0)hehe+=n;
            if(ring[hehe]==key[j]){
                picheidx=hehe;
                break;
            }
            pichesteps++;
        }


        int age = 1+agesteps + solve(ring,key,ageidx,j+1);
        int piche = 1+pichesteps + solve(ring,key,picheidx,j+1);

        return dp[i][j]= min(age,piche);    

    }
    int findRotateSteps(string ring, string key) {
        memset(dp,-1,sizeof(dp));
        return solve(ring,key,0,0);
    }
};