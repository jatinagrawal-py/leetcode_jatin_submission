class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1)return 1;
        //(y1-y2)x + (x2-x1)y + x1y2 - x2y1 = 0
        int maxi = INT_MIN;
        int n = points.size();
        for(int i = 0;i<n-1;i++){ // 1 wala
            for(int j = i+1;j<n;j++){ // 2 wala
                int count = 0;
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                for(int k = 0;k<n;k++){
                    int x = points[k][0];
                    int y = points[k][1];
                    if(((y1-y2)*x + (x2-x1)*y + x1*y2 - x2*y1)==0)count++;
                }
                maxi = max(maxi,count);
            }
        }
        return maxi;
    }
};