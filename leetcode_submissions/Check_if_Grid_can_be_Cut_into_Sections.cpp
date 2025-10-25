class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // x values ->  ||
        // y values ->  --

        vector<vector<int>>y;
        vector<vector<int>>x;

        for(auto it : rectangles){
            y.push_back({it[1],it[3]});
            x.push_back({it[0],it[2]});
        }

        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        int start= 0;
        int end= -1;
        int yint = 0;

        for(int i = 0;i<y.size();i++){
            start = y[i][0];
            if(end<=start){
                yint++;
            }
            end = max(end,y[i][1]);
        }

        if(yint>=3)return true;

        start= 0;
        end= -1;
        int xint = 0;

        for(int i = 0;i<x.size();i++){
            start = x[i][0];
            if(end<=start){
                xint++;
            }
            end = max(end,x[i][1]);
        }

        if(xint>=3)return true;

        return false;

    }
};