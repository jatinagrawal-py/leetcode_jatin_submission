class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        int maxele = INT_MIN;
        for(auto it:intervals){
            maxele = max(maxele,it[1]);
        }
        
        vector<int> prefix(maxele + 2, 0);

        for (auto it : intervals) {
            prefix[it[0]]++;
            prefix[it[1]+1]--;
        }

        int sum = 0, maxi = 0;
        
        for (auto &it : prefix) {
            sum += it;
            maxi = max(maxi, sum);
        }
        return maxi;

    }
};