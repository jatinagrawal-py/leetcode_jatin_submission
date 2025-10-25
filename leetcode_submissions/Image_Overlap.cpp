class Solution {
public:
    int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int rowoffset, int coloffset) {
        int n = img1.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int row = i + rowoffset;
                int col = j + coloffset;
                // Ensure row and col are within bounds
                if (row >= 0 && col >= 0 && row < n && col < n) {
                    // Count only if both positions have '1'
                    if (img1[row][col] == 1 && img2[i][j] == 1) {
                        result++;
                    }
                }
            }
        }
        return result;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int result = 0;

        for (int i = -n + 1; i < n; i++) {
            for (int j = -n + 1; j < n; j++) {
                result = max(result, overlap(img1, img2, i, j));
            }
        }
        return result;
    }
};
