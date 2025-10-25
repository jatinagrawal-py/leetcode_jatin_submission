class Solution {
public:
    long long dis(int x1 , int y1 , int x2 , int y2){
    long long a = 1LL * (x1 - x2) * (x1 - x2);
    long long b = 1LL * (y1 - y2) * (y1 - y2);
    return a + b;
    }


    int bfs(vector<vector<int>>& bombs , int n , int idx){
        vector<bool>vis(n,false);
        int count = 1;
        queue<int>pq;
        pq.push(idx);
        vis[idx]=true;

        while(!pq.empty()){
            int i = pq.front();
            pq.pop();
            

            for(int j = 0;j<n;j++){
                if(vis[j]!=true){
                    if(dis(bombs[i][0],bombs[i][1],bombs[j][0],bombs[j][1])<=1LL * bombs[i][2] * bombs[i][2]){
                        pq.push(j);
                        vis[j]=true;
                        count++;
                    }
                }
            }
        }

        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        int ans = INT_MIN;

        for(int i = 0;i<n;i++){
            int a = bfs(bombs,n,i);
            ans = max(ans,a);
        }

        return ans;
    }
};