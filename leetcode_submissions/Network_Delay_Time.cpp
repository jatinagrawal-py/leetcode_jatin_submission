class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto it:times){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int>result(n+1,INT_MAX);

        result[k]=0;

        pq.push({0,k});

        while(!pq.empty()){
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            for(auto it:adj[u]){
                int v = it.first;
                int wn = it.second;
                if(wn+d<result[v]){
                    result[v]=wn+d;
                    pq.push({wn+d,v});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1;i<n+1;i++){
            ans = max(ans,result[i]);
        }
        
        if(ans==INT_MAX)return -1;

        return ans;

    }
};