class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<p , vector<p> , greater<p>>pq;
        vector<vector<int>>dis(m , vector<int>(n , INT_MAX));
        vector<pair<int,int>>dir = {{1,0},{0,1}};
        dis[0][0] = grid[0][0];

        pq.push({grid[0][0],{0,0}});

        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();

            for(auto it:dir){
                int i = it.first + u;
                int j = it.second + v;
                if(i<m && i>=0 &&j<n && j>=0){
                    if(d+grid[i][j]<dis[i][j]){
                        dis[i][j]=d+grid[i][j];
                        pq.push({dis[i][j],{i,j}});
                    }
                }
            }
        }

        return dis[m-1][n-1];

    }
};