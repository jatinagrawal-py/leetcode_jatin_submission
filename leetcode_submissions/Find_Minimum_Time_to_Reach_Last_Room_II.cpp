class Solution {
public:
    vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
    typedef pair<int,pair<int,int>> p;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>>res(n , vector<int>(m,INT_MAX));
        priority_queue<p , vector<p> , greater<p>>pq;
        pq.push({0,{0,0}});
        res[0][0] = 0;
        
        while(!pq.empty()){
            int t = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            if(u==n-1 && v == m-1){
                return res[u][v];
            }
            

            for(auto it:directions){
                int newu = u+it.first;
                int newv = v + it.second;
                if(newu<n && newu>=0 && newv<m && newv>=0){
                    int needtime = max(0,moveTime[newu][newv]-t);
                    int k;
                    int steps = newu+newv ;
                    if(steps%2==1){
                        k=1;
                    }
                    else{
                        k=2;
                    }
                    int timereq = needtime+t+k;
                    if(res[newu][newv]>timereq){
                        res[newu][newv] = timereq ;
                        pq.push({timereq,{newu,newv}});
                    }
                }
            }
        }

        return -1;
    }
};