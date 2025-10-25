class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>temp;
        int i = x;
        int j = x+k-1;
        int a = y;
        int b = y+k-1;

        while(i<j){
            for(int hehe = a;hehe<=b;hehe++){
                swap(grid[i][hehe] , grid[j][hehe]);
            }
            i++;
            j--;
        }

        return grid;
    }
};