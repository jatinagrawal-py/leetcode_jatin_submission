class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n+1,0);
        for(auto it:bookings){
            ans[it[0]-1]+=it[2];
            ans[it[1]]-=it[2];
        }
        int sum = 0;
        for(auto &it : ans){
            sum+=it;
            it = sum;
        }
        vector<int>realans;
        for(int i = 0;i<n;i++)realans.push_back(ans[i]);

        return realans;
    }
};