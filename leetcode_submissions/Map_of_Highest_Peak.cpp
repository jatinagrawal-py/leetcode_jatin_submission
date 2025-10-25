class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<int,int>>pq;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(isWater[i][j]==1){
                    pq.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        vector<pair<int,int>>dir = {{0,1},{-1,0},{1,0},{0,-1}};
        int mini = 1;
        while(!pq.empty()){
            int si = pq.size();
            while(si--){
                int i = pq.front().first;
                int j = pq.front().second;
                pq.pop();
                for(auto it:dir){
                    int newi = i + it.first;
                    int newj = j+ it.second;
                    if(newi<m && newi>=0 && newj<n && newj>=0){
                        if(ans[newi][newj]==-1){
                            ans[newi][newj] = mini;
                            pq.push({newi,newj});
                        }
                    }
                }
            }
            mini++;
        }
        return ans;
    }
};