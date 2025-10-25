class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(queries.size(), 0);
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        vector<pair<int, int>> sorted_queries;
        for (int i = 0; i < queries.size(); i++) {
            sorted_queries.push_back({queries[i], i});
        }
        
        sort(sorted_queries.begin(), sorted_queries.end()); // Sort queries in increasing order
        
        int points = 0; // Number of cells accessible for the current threshold
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        
        int query_index = 0;
        
        for (auto [query_value, original_index] : sorted_queries) {
            while (!pq.empty() && pq.top().first < query_value) {
                auto [cell_value, cell] = pq.top();
                pq.pop();
                points++;
                
                int i = cell.first, j = cell.second;
                
                for (auto [dx, dy] : directions) {
                    int ni = i + dx, nj = j + dy;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) {
                        pq.push({grid[ni][nj], {ni, nj}});
                        vis[ni][nj] = 1;
                    }
                }
            }
            ans[original_index] = points;
        }
        
        return ans;
    }
};
