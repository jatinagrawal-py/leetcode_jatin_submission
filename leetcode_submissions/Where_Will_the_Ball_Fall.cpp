class Solution {
public:
    int solve(vector<vector<int>>& grid , int i,int row,int col){

        for(int j = 0;j<row;j++){
            if(grid[j][i]==1){
                if(i<col-1){
                    if(grid[j][i+1]!=-1){
                        i++;
                        continue;
                    }
                }
                return -1;
            }
            else{
                if(i>0){
                    if(grid[j][i-1]!=1){
                        i--;
                        continue;
                    }
                }
                return -1;
            }
        }

        return i;

    }

    vector<int> findBall(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int>ans(col);

        for(int i = 0;i<col;i++){
            ans[i] = solve(grid,i,row,col);
        }


        return ans;
    }
};