class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;

        
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < n; ++i) {
            graph[arr[i]].push_back(i);
        }

        vector<bool> vis(n, false);
        vis[0] = true;

        queue<int> q;
        q.push(0);
        int steps = 0;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int u = q.front(); q.pop();
                if(u == n - 1) return steps;

               
                if(u - 1 >= 0 && !vis[u - 1]) {
                    q.push(u - 1);
                    vis[u - 1] = true;
                }

                
                if(u + 1 < n && !vis[u + 1]) {
                    q.push(u + 1);
                    vis[u + 1] = true;
                }

                for(int v : graph[arr[u]]) {
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }

                graph[arr[u]].clear();
            }
            steps++;
        }

        return -1;
    }
};
