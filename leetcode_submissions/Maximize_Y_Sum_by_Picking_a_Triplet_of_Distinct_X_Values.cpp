class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        // 1 1 2 2 3 
        // 2 3 4 5 6

        // 2 9 13 13
        // 1 1 2 9
        int n = x.size();
        vector<pair<int, int>> xy;
        for (int i = 0; i < n; i++) {
            xy.push_back({y[i], x[i]});  
        }

        sort(xy.rbegin(), xy.rend());

        unordered_set<int> used;
        int sum = 0, count = 0;

        for (auto& p : xy) {
            if (used.count(p.second) == 0) {
                used.insert(p.second);
                sum += p.first;
                count++;
                if (count == 3) break;
            }
        }

        return count == 3 ? sum : -1;
    }
};