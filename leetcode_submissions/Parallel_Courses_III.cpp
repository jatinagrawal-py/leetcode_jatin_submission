class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // jinki indegree same hai woh simultaneously?

        vector<int>indegree(n+1,0);
        unordered_map<int,vector<int>>mpp;
        vector<int>maxi(n+1,0);

        for(auto it:relations){
            int prev = it[0];
            int next = it[1];
            indegree[next]++;
            mpp[prev].push_back(next);
        }
        
        priority_queue<int , vector<int>,greater<int>>pq;

        for(int i = 1;i<=n;i++){
            if(indegree[i]==0){
                pq.push(i);
                maxi[i]=time[i-1];
            }
        }

        while(!pq.empty()){
            int si = pq.size();
            int temp=INT_MIN;
            while(si--){
                int u= pq.top();
                pq.pop();

                for(auto it:mpp[u]){
                    indegree[it]--;
                    if(maxi[it]<maxi[u]+time[it-1]){
                        maxi[it]=maxi[u]+time[it-1];
                    }
                    if(indegree[it]==0){
                        pq.push(it);
                    }
                }
            }
        }

        return *max_element(begin(maxi),end(maxi));
    }
};