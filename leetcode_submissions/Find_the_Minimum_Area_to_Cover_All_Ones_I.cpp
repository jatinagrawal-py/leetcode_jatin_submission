class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        // left right top bottom
        // left -> col ka min
        // right -> col ka max
        // top -> row ka min
        // bottom row ka min
        // return (right-lef+1)*(bottom-top+1);
        int left = INT_MAX;
        int right = INT_MIN;
        int top = INT_MAX;
        int bottom = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(grid[i][j]==1){
                    left = min(left,j);
                    right = max(right,j);
                    top = min(i,top);
                    bottom = max(i,bottom);
                }
            }
        }
        if(left==INT_MAX)return 0;

        return (right-left+1)*(bottom-top+1);
    }
};