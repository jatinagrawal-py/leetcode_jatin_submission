class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int count = 0;
        int till = startFuel;
        int i = 0;
        int n = stations.size();

        while (till < target) {
            while (i < n && stations[i][0] <= till) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty()) return -1;

            till += pq.top();
            pq.pop();
            count++;
        }

        return count;
    }
};
