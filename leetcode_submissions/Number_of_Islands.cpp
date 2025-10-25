class Solution {
public:
    vector<pair<int,int>>dir = {{1,0},{0,-1},{0,1},{-1,0}};
    void dfs(int u , int v , vector<vector<int>>&vis ,int  n ,int m , vector<vector<char>>& grid){
        vis[u][v]=1;

        for(auto it:dir){
            int newu = it.first+u;
            int newv = it.second+v;
            if(newu<m && newv <n && newu>=0 && newv>=0){
                if(vis[newu][newv]==-1 && grid[newu][newv]=='1'){
                    dfs(newu,newv , vis , n , m , grid);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(vis[i][j]==-1 && grid[i][j]=='1'){
                    dfs(i,j,vis, n ,m ,grid);
                    count++;
                }
            }
        }

        return count;
    }
};