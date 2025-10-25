class Solution {
public:
    struct State {
        int x, y, energyLeft, litterMask, steps;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int totalLitter = 0;
        unordered_map<int, int> litterIndex; // encode (i * n + j) as key
        int startX = -1, startY = -1;

        // Locate 'S' and all 'L'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litterIndex[i * n + j] = totalLitter++;
                }
            }
        }

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        // 4D visited array: x, y, energy, litterMask
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << totalLitter, false)
                )
            )
        );

        queue<State> q;
        q.push({startX, startY, energy, 0, 0});
        visited[startX][startY][energy][0] = true;

        while (!q.empty()) {
            State curr = q.front();
            q.pop();

            // If all litter collected
            if (curr.litterMask == (1 << totalLitter) - 1)
                return curr.steps;

            for (auto [dx, dy] : directions) {
                int nx = curr.x + dx;
                int ny = curr.y + dy;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (classroom[nx][ny] == 'X') continue;

                int newEnergy = curr.energyLeft - 1;
                if (newEnergy < 0) continue;

                // Reset energy if on 'R'
                if (classroom[nx][ny] == 'R') newEnergy = energy;

                int newMask = curr.litterMask;
                if (classroom[nx][ny] == 'L') {
                    int key = nx * n + ny;
                    newMask |= (1 << litterIndex[key]);
                }

                if (!visited[nx][ny][newEnergy][newMask]) {
                    visited[nx][ny][newEnergy][newMask] = true;
                    q.push({nx, ny, newEnergy, newMask, curr.steps + 1});
                }
            }
        }

        return -1;
    }
};
