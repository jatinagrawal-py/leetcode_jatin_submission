class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    int swimInWater(vector<vector<int>>& grid) {
        int t = grid[0][0];
        priority_queue< pp , vector<pp> , greater<pp>>pq;
        pq.push({t,{0,0}});
        int n = grid.size();
        grid[0][0]=-1;
        vector<pair<int,int>>dir = {{1,0},{0,-1},{0,1},{-1,0}};
        while(!pq.empty()){
            int oldt = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(i==n-1 && j ==n-1)return oldt;
            for(auto it:dir){
                int newi = i+it.first;
                int newj = j+it.second;
                if(newi<n && newj<n && newi>=0 && newj>=0 && grid[newi][newj]!=-1){
                    pq.push({max(oldt,grid[newi][newj]),{newi,newj}});
                    grid[newi][newj]=-1;
                }
            }
        }
        return -1;
    }
};