class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];

        vector<int> indegree(numCourses,0);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        vector<int>result ;
        int count = 0;
        queue<int>q;

        for(int i =0;i<numCourses ;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }

        while(!q.empty()){
            int u = q.front();
            result.push_back(u);
            q.pop();

            for(auto it : adj[u]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    count++;
                }
            }
        }

        if(count == numCourses) return result;

        return {};
    }
};