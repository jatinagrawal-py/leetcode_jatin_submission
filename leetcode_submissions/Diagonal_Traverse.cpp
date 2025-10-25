class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> mpp;
        int row = mat.size();
        int col = mat[0].size();

        // Step 1: Store elements in map according to sum (i + j)
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mpp[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;
        // Step 2: Traverse map and process diagonals in zigzag order
        for (auto& it : mpp) {
            vector<int>& diag = it.second; // Get diagonal elements
            if (it.first % 2 == 0) {
                // Even-indexed diagonals should be reversed (bottom-left to top-right)
                reverse(diag.begin(), diag.end());
            }
            ans.insert(ans.end(), diag.begin(), diag.end());
        }
        return ans;
    }
};
