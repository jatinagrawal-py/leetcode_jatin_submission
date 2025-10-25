class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int delr[] = {-1,0,0,1};
        int delc[] = {0,-1,1,0};

        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;

        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }

    
        while(!q.empty()){
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+delr[i];
                int nc = c+delc[i];
                if(nr<n && nc<m && nc>=0 && nr>=0){
                    if(mat[nr][nc]==1 && vis[nr][nc]==0){
                        q.push({d+1,{nr,nc}});
                        vis[nr][nc]=1;
                        dis[nr][nc]=d+1;
                    }
                }
            }
        }

        return dis;

    }
};