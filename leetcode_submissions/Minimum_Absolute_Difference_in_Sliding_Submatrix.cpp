class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col, int k) {
        
        unordered_set<int>st;
        for(int i = row; i < row + k; i++) {
            for(int j = col; j < col + k; j++) {
                st.insert(grid[i][j]);
            }
        }
        if(st.size()==1)return 0;

        vector<int> elements(st.begin(),st.end());
        
        sort(elements.begin(), elements.end());

        int mini = INT_MAX;
        for(int i = 1; i < elements.size(); i++) {
            mini = min(mini, elements[i] - elements[i-1]);
        }
        
        return mini;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for(int i = 0; i <= m - k; i++) {
            for(int j = 0; j <= n - k; j++) {
                ans[i][j] = solve(grid, i, j, k);
            }
        }

        return ans;
    }
};
