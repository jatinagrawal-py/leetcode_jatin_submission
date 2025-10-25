class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int p = points.size();
        int q = queries.size();
        vector<int> ans(q);
        for(int i =0;i<q;i++){
            int a =0;
            for(int j=0;j<p;j++){
                float d = 0;
                d = sqrt((points[j][0]-queries[i][0])*(points[j][0]-queries[i][0]) + (points[j][1]-queries[i][1])*(points[j][1]-queries[i][1]));
                if(queries[i][2]>=d){
                    a=a+1;
                }
            }
            ans[i]=a;
        }
        return ans;
    }
};