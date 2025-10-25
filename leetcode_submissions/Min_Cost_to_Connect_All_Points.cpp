class Solution {
public:
    typedef pair<int,int> P;
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<bool>inMST(points.size(),false);

        pq.push({0,0});

        int sum = 0;

        while(!pq.empty()){
            int wt = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            if(inMST[ind]==true)continue;
            inMST[ind]=true;
            sum+=wt;

            for(int i = 0;i<points.size();i++){
                if(inMST[i]==true)continue;

                int x1 = points[ind][0];
                int y1 = points[ind][1];
                int x2 = points[i][0];
                int y2 = points[i][1];
                int w = abs(x1-x2) + abs(y1-y2);
                pq.push({w,i});
            }

        }


        return sum;

    }
};