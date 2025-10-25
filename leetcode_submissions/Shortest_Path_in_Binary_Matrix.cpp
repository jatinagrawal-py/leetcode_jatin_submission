#include <vector>
#include <queue>
#include <utility>  // For std::pair
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Check if start or end is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        // Distance matrix initialized with a large number
        vector<vector<int>> distance(n, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q;

        distance[0][0] = 1;  // Start cell distance
        q.push({1, {0, 0}});

        // 8 possible directions (8-connected grid)
        int delr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            int r = q.front().second.first;
            int c = q.front().second.second;
            int dis = q.front().first;
            q.pop();

            // Explore all 8 possible directions
            for (int i = 0; i < 8; i++) {
                int nr = r + delr[i];
                int nc = c + delc[i];

                // Check if the new position is within bounds and is open
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    // If visiting this cell results in a shorter path
                    if (dis + 1 < distance[nr][nc]) {
                        distance[nr][nc] = dis + 1;
                        q.push({dis + 1, {nr, nc}});
                    }
                }
            }
        }

        // Check if the bottom-right corner is reachable
        return distance[n - 1][n - 1] == 1e9 ? -1 : distance[n - 1][n - 1];
    }
};
