class Solution {
private:
    void dfs(int sc, int sr, vector<vector<int>>& ans, int color, int ini) {
        ans[sr][sc] = color;
        int n = ans.size();
        int m = ans[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nsr = sr + delrow[i];
            int nsc = sc + delcol[i];
            if (nsr >= 0 && nsc >= 0 && nsr < n && nsc < m) {
                if (ans[nsr][nsc] == ini) {
                    dfs(nsc, nsr, ans, color, ini);
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini = image[sr][sc];
        if (ini != color) {  // Avoid redundant work if the color is the same
            vector<vector<int>> ans = image;
            dfs(sc, sr, ans, color, ini);
            return ans;
        }
        return image;
    }
};
