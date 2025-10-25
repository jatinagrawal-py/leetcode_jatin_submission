class Solution {
public:
int dp[100001][14];
int dfs(int node, int parent , int p , vector<int>& coins, int k,
        unordered_map<int, vector<int>>& mpp) {

    if(p>=14)return 0;
    if(dp[node][p]!=-1) return dp[node][p];
    int case1= (coins[node]>>p)-k;
    int case2 = (coins[node]>>(p+1));

    for (auto it : mpp[node]) {
        if (it!=parent) {
            case1+= dfs(it,node,p,coins,k,mpp);
            case2+= dfs(it,node,p+1,coins,k,mpp);
        }
    }

    return dp[node][p]= max(case1,case2);
}
   
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {

        unordered_map<int,vector<int>>mpp;
        for(auto it:edges){
            mpp[it[0]].push_back(it[1]);
            mpp[it[1]].push_back(it[0]);
        }
        memset(dp,-1,sizeof(dp));
        return dfs(0,-1,0,coins,k,mpp);
    }
};