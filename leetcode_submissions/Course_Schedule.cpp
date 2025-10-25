class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        //(a,b) = b->a;

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        queue<int> q;

        vector<int> indegree(numCourses,0);
        
        for(int i = 0;i<numCourses;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        int count = 0;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto it : adj[u]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    count++;
                }
            }
        }

        if(count == numCourses)return true;

        return false;

    }
};