class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();

        vector<int>lis;
        vector<int>res(n);

        for(int i = 0;i<n;i++){
            int idx = upper_bound(begin(lis),end(lis),obstacles[i])-begin(lis);

            if(idx==lis.size()){
                lis.push_back(obstacles[i]);
            }
            else{
                lis[idx] = obstacles[i];
            }

            res[i]= idx+1;
        }

        return res;
    }
};