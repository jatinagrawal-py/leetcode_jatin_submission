class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // most frequent color ke number of nodes = color value
        // and usmai se largest number batana hai 
        // [1,k]
        unordered_map<int,vector<int>>adj;
        int n = colors.size();
        vector<int>indegree(n,0);

        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            indegree[v]++;
            adj[u].push_back(v);
        }

        vector<vector<int>> t(n, vector<int>(26, 0));

        queue<int>pq;
        for(int i = 0;i<n;i++){
            if(indegree[i]==0){
                pq.push(i);
                t[i][colors[i]-'a']=1;
            }
        }

        int res = INT_MIN;
        int count = 0;

        while(!pq.empty()){
            int u = pq.front();
            pq.pop();
            count++;
            res = max(res,t[u][colors[u]-'a']);

            for(auto it:adj[u]){
                int x = colors[it]-'a';
                for(int i = 0;i<26;i++){
                    if(i==x){
                        t[it][i] = max(t[it][i],t[u][i]+1);
                    }
                    else{
                        t[it][i] = max(t[it][i],t[u][i]);
                    }
                }
                indegree[it]--;
                if(indegree[it]==0){
                    pq.push(it);
                }
            }
        }

        if(count!=n){
            return -1;
        }

        return res;

    }
};