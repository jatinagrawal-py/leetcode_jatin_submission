class Solution {
public:
    void dfs(int u , vector<int>& dis , vector<int>& edges , int d ){

        dis[u]=d;

        if(edges[u]!=-1 && dis[edges[u]]>(dis[u]+1)){
            dfs(edges[u],dis,edges,d+1);
        }

        return;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>dis1(n,INT_MAX);
        vector<int>dis2(n,INT_MAX);


        dfs(node1,dis1,edges,0);
        dfs(node2,dis2,edges,0);


        int ans = -1, best = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (dis1[i] != INT_MAX && dis2[i] != INT_MAX) {
                int mx = max(dis1[i], dis2[i]);
                if (mx < best) {
                    best = mx;
                    ans = i;
                }
            }
        }
        return ans;
    }
};