class Solution {
public:
    vector<pair<int,int>> directions = {{1,0},{0,-1},{0,1},{-1,0}};
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k, vector<vector<int>>& vis, int m, int n) {
        if (k == word.size()) return true;
        
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || board[i][j] != word[k])
            return false;

        vis[i][j] = 1;

        for (auto dir : directions) {
            int newi = i + dir.first;
            int newj = j + dir.second;
            if (dfs(board, word, newi, newj, k + 1, vis, m, n))
                return true;
        }

        vis[i][j] = 0; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, vis, m, n))
                        return true;
                }
            }
        }
        return false;
    }
};
