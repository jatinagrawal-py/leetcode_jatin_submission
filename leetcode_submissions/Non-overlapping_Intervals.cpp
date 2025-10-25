class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto lambda = [](auto & p1 , auto & p2){
            if(p1[1]<p2[1])return true;

            return false;
        };

        sort(intervals.begin(),intervals.end(),lambda);

        int count = 0;
        int prev = INT_MIN;

        for(auto it:intervals){
            if(it[0]>=prev){
                count++;
                prev = max(prev,it[1]);
            }
        }

        return intervals.size()-count;
    }
};