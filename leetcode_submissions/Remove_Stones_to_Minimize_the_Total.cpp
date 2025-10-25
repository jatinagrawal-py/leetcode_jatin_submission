class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end()); // Max-heap

        while (k-- > 0) {
            int x = pq.top();
            pq.pop();
            x = (x + 1) / 2;  // Ceiling of x / 2
            pq.push(x);
        }

        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};
