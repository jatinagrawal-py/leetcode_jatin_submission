class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>>t(m , vector<int>(n,0));

        int res = 0;
        for(int i = 0;i<m;i++){
            if(matrix[i][0]=='1'){
                t[i][0]=1;
                res=1;
            }
        }
        for(int j = 0;j<n;j++){
            if(matrix[0][j]=='1'){
                t[0][j]=1;
                res=1;
            }
        }

        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(matrix[i][j]=='1'){
                    t[i][j] = 1 + min({t[i-1][j] , t[i][j-1] , t[i-1][j-1]});
                    res = max(res,t[i][j]);
                }
            }
        }

        return res*res;
    }
};