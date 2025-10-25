class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterDuration.size();
        int minFinish = INT_MAX;

        for(int i = 0;i<n;i++){
            int landStart = landStartTime[i];
            int landEnd = landStart + landDuration[i];

            for(int j = 0;j<m;j++){
                int waterStart = waterStartTime[j];
                int waterEnd = waterStart + waterDuration[j];

                int time1 = max(waterStart, landEnd) + waterDuration[j];

                int time2 = max(landStart, waterEnd) + landDuration[i];

                minFinish = min({minFinish, time1, time2});
            }
        }

        return minFinish;
    
       
    }
};