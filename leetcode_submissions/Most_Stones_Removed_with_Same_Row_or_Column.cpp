class Solution {
public:
    void dfs(vector<vector<int>>& stones , int i , int u , int v , vector<int>&vis ){
        vis[i]=1;

        for(int j = 0;j<stones.size();j++){
            if(vis[j]!=1 && (u==stones[j][0] || v==stones[j][1] )){
                dfs(stones,j,stones[j][0],stones[j][1],vis);
            }
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int grp = 0;
        vector<int>vis(n,0);

        for(int i = 0;i<n;i++){
            if(vis[i]!=1){
                dfs(stones,i,stones[i][0], stones[i][1],vis);
                grp++;
            }
        }

        return n-grp;
    }
};