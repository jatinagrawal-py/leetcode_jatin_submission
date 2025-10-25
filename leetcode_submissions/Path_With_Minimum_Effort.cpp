class Solution {
public:
    vector<vector<int>> distance = {{1,0},{0,1},{-1,0},{0,-1}};

    bool issafe(int i , int j , int row , int col){
        return i >= 0 && i < row && j >= 0 && j < col;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        
        if (row == 1 && col == 1) return 0;

        vector<vector<int>> result(row, vector<int>(col, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();  // Don't forget to pop the top element

            if (i == row - 1 && j == col - 1) return dis;  // Early exit when reaching destination

            for (auto it : distance) {
                int newi = i + it[0];
                int newj = j + it[1];

                if (issafe(newi, newj, row, col)) {
                    int newdis = max(abs(heights[i][j] - heights[newi][newj]), dis);
                    if (newdis < result[newi][newj]) {
                        result[newi][newj] = newdis;
                        pq.push({newdis, {newi, newj}});
                    }
                }
            }
        }

        return result[row - 1][col - 1];
    }
};
