class Solution {
public:
    vector<vector<double>> dp;
    double solve(int poured, int i, int j){
        if(i<0 || j<0 || i<j){
            return 0.0;
        }
        if(i==0 && j==0)return poured;

        if(dp[i][j]!=-1.0) return dp[i][j];

        double left_up = (solve(poured,i-1,j-1)-1)/2;
        double right_up = (solve(poured,i-1,j)-1)/2;

        if(left_up<0) left_up = 0.0;
        if(right_up<0) right_up = 0.0;
        

        return dp[i][j]= left_up + right_up;

    }
    double champagneTower(int poured, int query_row, int query_glass) {
        dp.assign(102, vector<double>(102, -1.0)); 
        return min(1.0,solve(poured,query_row,query_glass));
    }
};