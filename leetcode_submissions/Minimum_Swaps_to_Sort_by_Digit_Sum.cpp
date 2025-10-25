#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> sortedWithIndex(n); // {digitSum, originalIndex}

        for (int i = 0; i < n; ++i) {
            sortedWithIndex[i] = {digitSum(nums[i]), i};
        }

        // Sort by digit sum, if tie, by actual number to maintain stability
        sort(sortedWithIndex.begin(), sortedWithIndex.end(), [&](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) return nums[a.second] < nums[b.second];
            return a.first < b.first;
        });

        // Visited array
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || sortedWithIndex[i].second == i) {
                continue; // already in correct position
            }

            int cycle_size = 0;
            int j = i;

            // Find size of cycle
            while (!visited[j]) {
                visited[j] = true;
                j = sortedWithIndex[j].second;
                cycle_size++;
            }

            if (cycle_size > 1) {
                swaps += cycle_size - 1;
            }
        }

        return swaps;
    }
};
