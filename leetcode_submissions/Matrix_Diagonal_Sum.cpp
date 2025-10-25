class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat[0].size();
        int j1 = 0;
        int j2 = n-1;
        int sum =0;
        for(int i =0;i<n;i++){
            if(j1==j2){
                sum = sum+mat[i][j1];
                j1++;
                j2--;
                continue;
            }
            sum = sum + mat[i][j1]+mat[i][j2];
            j1++;
            j2--;
        }
        return sum;
    }
};