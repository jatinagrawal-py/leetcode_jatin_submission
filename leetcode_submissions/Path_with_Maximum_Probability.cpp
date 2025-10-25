class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>adj;

        for(int i = 0 ; i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<double,int>>pq;
        vector<double>ans(n,0.0);

        pq.push({1,start_node});
        ans[start_node]=1;

        while(!pq.empty()){
            double p = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(auto it:adj[u]){
                int v = it.first;
                double wt = it.second;
                if(ans[v]<p*wt){
                    ans[v] = p*wt;
                    pq.push({ans[v],v});
                }
            }
        }

        

        return ans[end_node];
    }
};