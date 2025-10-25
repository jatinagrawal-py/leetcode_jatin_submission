class Graph {
public:
    unordered_map<int,vector<pair<int,int>>>mpp;
    int n ;

    Graph(int n, vector<vector<int>>& edges) {

        this->n = n;
        for(auto it:edges){
            int from = it[0];
            int to = it[1];
            int cost = it[2];
            mpp[from].push_back({to,cost});
        }

    }
    
    void addEdge(vector<int> it) {
        
            int from = it[0];
            int to = it[1];
            int cost = it[2];
            mpp[from].push_back({to,cost});
        
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dis(n,INT_MAX);
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;

        dis[node1]=0;
        pq.push({0,node1});

        while(!pq.empty()){
            auto hehe = pq.top();
            int u = hehe.second;
            int cost = hehe.first;
            pq.pop();

            for(auto it:mpp[u]){
                int newdis = it.second;
                int v = it.first;

                if(dis[v]>cost+newdis){
                    dis[v]=cost+newdis;
                    pq.push({dis[v],v});
                }
            }
        }

        return dis[node2]==INT_MAX?-1:dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */