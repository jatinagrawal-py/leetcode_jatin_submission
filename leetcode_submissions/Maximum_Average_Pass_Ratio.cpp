class Solution {
public:
    typedef pair<double,pair<int,int>> P;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<P,vector<P>>pq;

        for(auto it:classes){
            double avg = ((double)(it[0]+1)/(it[1]+1))-((double)it[0]/it[1]);
            pq.push({avg,{it[0],it[1]}});
        }

        while(extraStudents){
            auto hehe = pq.top();
            double curavgdiff = hehe.first;
            int u = hehe.second.first;
            int v = hehe.second.second;
            double newavgdiff = ((double)(u+2)/(v+2))-((double)(u+1)/(v+1));
            pq.pop();
            pq.push({newavgdiff,{u+1,v+1}});
            extraStudents--;
        }

        double ans = 0.0;
        int n = pq.size();

        while(!pq.empty()){
            ans+=((double)pq.top().second.first/pq.top().second.second);
            pq.pop();
        }

        ans = ans/n;

        return ans;

    }
};