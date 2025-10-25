class Solution {
public:
    int m = 1e9 + 7;
    typedef pair<long long , int> P;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,vector<pair<int,int>>> adj;
        priority_queue<P,vector<P>,greater<P>>pq;

        for(auto it: roads){
            int u = it[0];
            int v = it[1];
            int time = it[2];

            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }

        vector<long long> result(n,LLONG_MAX);
        vector<int>pathcount(n,0);

        result[0]=0;
        pathcount[0]=1;

        pq.push({0,0});

        while(!pq.empty()){
            long long curtime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                long long time = it.second;
                int neig = it.first;

                if(time+curtime<result[neig]){
                    result[neig]=time+curtime;
                    pq.push({result[neig],neig});
                    pathcount[neig]=pathcount[node];
                }
                else if(time+curtime==result[neig]){
                    pathcount[neig] = (pathcount[neig] + pathcount[node])%m;
                }
            }
        }

        return pathcount[n-1];

    }
};