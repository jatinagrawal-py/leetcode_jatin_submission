class Solution {
public:
    int bfs(unordered_map<int,vector<pair<int,int>>>&adj , int i , int n , int d){
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
        pq.push({0,i});
        vector<int>dis(n,INT_MAX);
        dis[i] = 0;
        int hehe = 0;

        while(!pq.empty()){
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            for(auto it:adj[u]){
                if(wt+it.second<dis[it.first]){
                    pq.push({wt+it.second,it.first});
                    dis[it.first] = wt+it.second;
                }
            }
        }

        for(auto it:dis){
            if(it<=d){
                hehe++;
            }
        }


        return hehe;

    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<pair<int,int>>arr;

        for(int i = 0;i<n;i++){
            int nodes = bfs(adj , i , n , distanceThreshold);
            arr.push_back({nodes,i});
        }

        sort(arr.begin(),arr.end());

        sort(arr.begin(), arr.end(), [](pair<int,int>& a, pair<int,int>& b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        return arr[0].second;
    }
};