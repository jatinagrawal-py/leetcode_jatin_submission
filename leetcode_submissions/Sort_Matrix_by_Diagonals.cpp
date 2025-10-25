class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        // 1 1 1 
        // 1 1 1
        // 1 1 1

        // 1 1 1 1
        // 1 1 1 1
        // 1 1 1 1
        // 1 1 1 1

        // bottom left + diagonal main -> decreasing order
        // top right -> incfeasdong porder

        // 0-> n-1
        // -1 -> n-2
        unordered_map<int,vector<int>>mpp;
        int n = grid.size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                mpp[j-i].push_back(grid[i][j]);
            }
        }

        for(auto &it : mpp){
            if(it.first>0){
                sort(begin(it.second),end(it.second));
            }
            else{
                sort(rbegin(it.second),rend(it.second));
            }
            
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                grid[i][j] = mpp[j-i][min(j,i)];
            }
        }
        

        return grid;

    }
};