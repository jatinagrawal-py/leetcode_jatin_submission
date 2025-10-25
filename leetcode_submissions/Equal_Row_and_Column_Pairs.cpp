class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>>col;

        int n = grid.size();

        for(int i = 0 ; i<n;i++){
            vector<int>temp;
            for(int j = 0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            col.push_back(temp);
        }

        int ans =0;

        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                if(col[j]==grid[i]){
                    ans++;
                }
            }
        }


        return ans;
    }
};