class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>pq;
        int time = -1;
        int m = grid.size();
        int n = grid[0].size();
        int countor = 0;
        
        vector<pair<int,int>>dir = {{-1,0},{0,-1},{0,1},{1,0}};
        int total = 0;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==2){
                    pq.push({i,j});
                    grid[i][j]=-1;
                }
                else if(grid[i][j]==1){countor++;}
                else  total++;
            }
        }
        
        if(total==n*m)return 0;
        
        while(!pq.empty()){
            int si = pq.size();
            while(si--){
                int i = pq.front().first;
                int j = pq.front().second;
                pq.pop();
                
                for(auto it:dir){
                    int newi = it.first+i;
                    int newj = it.second+j;
                    if(newi>=0 && newj>=0 && newi<m && newj<n && grid[newi][newj]!=-1){
                        if(grid[newi][newj]==1){
                            pq.push({newi,newj});
                            countor--;
                        }
                        grid[newi][newj]=-1;
                    }
                
                }
            }
            time++;
        }
        
        if(countor==0)return time;
        
        return -1;
    }
};