class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    queue<pair<int, int>> q;

    void dfs(int i, int j, vector<vector<int>>& grid, int n) {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1)
            return;

        grid[i][j] = -1;
        q.push({i, j});

        for (auto [dx, dy] : dir) {
            dfs(i + dx, j + dy, grid, n);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool found = false;

        
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, n);
                    found = true;
                }
            }
        }

        int level = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : dir) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                        if (grid[nx][ny] == 1) {
                            return level; 
                        }
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny] = -1;
                            q.push({nx, ny});
                        }
                    }
                }
            }

            level++;
        }

        return -1;
    }
};
