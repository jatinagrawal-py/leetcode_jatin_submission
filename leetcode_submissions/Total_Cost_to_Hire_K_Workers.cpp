class Solution {
public:
    typedef pair<int, int> P;
    long long totalCost(vector<int>& costs, int k, int c) {
        int n = costs.size();
        int i = 0, j = n - 1;

        priority_queue<P, vector<P>, greater<P>> pq;
        
        for (int count = 0; count < c && i <= j; count++) {
            pq.push({costs[i], i});
            i++;
        }

        for (int count = 0; count < c && i <= j; count++) {
            pq.push({costs[j], j});
            j--;
        }

        long long ans = 0;

        while (k-- && !pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            ans += val;

            if (i <= j) {
                if (idx < i) {
                    pq.push({costs[i], i});
                    i++;
                } else {
                    pq.push({costs[j], j});
                    j--;
                }
            }
        }

        return ans;
    }
};
