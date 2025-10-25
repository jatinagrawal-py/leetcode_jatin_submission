class Solution {
public:
    typedef pair<int,pair<int,int>>pp;
    int trapRainWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue< pp , vector<pp> , greater<pp>>pq;
        vector<vector<bool>>vis(m,vector<bool>(n,false));

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if((i==0 && j==0) || (i==m-1 && j==n-1) || (i==m-1 && j==0) || (i==0 && j==n-1))continue;
                else if(i==0){
                    pq.push({grid[i][j],{i,j}});
                    vis[i][j]=true;
                }
                else if(j==0){
                    pq.push({grid[i][j],{i,j}});
                    vis[i][j]=true;
                }
                else if(i==m-1){
                    pq.push({grid[i][j],{i,j}});
                    vis[i][j]=true;
                }
                else if(j==n-1){
                    pq.push({grid[i][j],{i,j}});
                    vis[i][j]=true;
                }
            }
        }
        vector<pair<int,int>>dir = {{1,0},{0,-1},{0,1},{-1,0}};
        int count = 0;

        while(!pq.empty()){
            int si = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for(auto it:dir){
                int newi = it.first+i;
                int newj = it.second+j;
                if(newi>0 && newj>0 && newi<m-1 && newj<n-1){
                    if(vis[newi][newj]==false){
                        int newsi = max(si-grid[newi][newj],0);
                        count+=newsi;
                        if(newsi==0){
                            pq.push({grid[newi][newj],{newi,newj}});
                        }
                        else{
                            pq.push({si,{newi,newj}});
                        }
                        vis[newi][newj]=true;
                    }
                }
            }
        }

        return count;
    }
};