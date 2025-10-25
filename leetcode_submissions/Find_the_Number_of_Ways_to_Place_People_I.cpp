class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // x mai bada and y mai chota chaiye 

       auto lambda = [](const auto &p1, const auto &p2) {
            if (p1[0] != p2[0]) {
                return p1[0] > p2[0];  
            }
            return p1[1] < p2[1];  
        };

        sort(points.begin(), points.end(), lambda);

        int count = 0;
        int n = points.size();

        for(int i = 0;i<n-1;i++){
            
            for(int j = i+1;j<n;j++){
                
                if(points[i][0]>=points[j][0] && points[i][1]<=points[j][1]){
                    bool flag = false;
                    for(int k = 0;k<n;k++){
                        if(k!=i && k!=j){
                            if((points[k][0]<=points[i][0] && points[k][0]>=points[j][0]) &&  (points[k][1]>=points[i][1] && points[k][1]<=points[j][1])){
                                flag = true;
                                break;
                            }
                        }
                    }
                    if(flag==false)count++;
                }
                
            }
        }
        return count;
    }
};