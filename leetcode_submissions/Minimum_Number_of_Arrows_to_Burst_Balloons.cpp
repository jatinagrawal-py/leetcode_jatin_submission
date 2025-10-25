class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());

        int count = 1;
        vector<int>prev = points[0];

        for(int i = 1;i<n;i++){
            int prevs = prev[0];
            int preve = prev[1];

            int currs = points[i][0];
            int curre = points[i][1];

            if(currs>preve){
                count++;
                prev = points[i];
            }
            else{
                prev[0] = max(currs , prevs);
                prev[1] = min(curre , preve);
            }
        }
        return count;
    }
};