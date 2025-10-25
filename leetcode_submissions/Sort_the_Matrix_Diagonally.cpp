class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        //col-1 ->= 0  /// row+1->=row-1

        int row = mat.size();
        int col = mat[0].size();

        if(row==1 && col ==1){
            return mat;
        }

        for(int k =col-1;k>=0;k--){
            vector<int>diag;
            int i = 0 ; 
            int j = k;
            while(i<row && j<col){
                diag.push_back(mat[i][j]);
                i++;
                j++;
            }
            int l = diag.size();
            sort(diag.begin(),diag.end());
            i = 0 ; 
            j = k;
            for(int m = 0;m<l;m++){
                mat[i][j]=diag[m];
                i++;
                j++;
            }
        }

        for(int k =1;k<=row-1;k++){
            vector<int>diag;
            int i = k ; 
            int j = 0;
            while(i<row && j<col){
                diag.push_back(mat[i][j]);
                i++;
                j++;
            }
            int l = diag.size();
            sort(diag.begin(),diag.end());
            i = k ; 
            j = 0;
            for(int m = 0;m<l;m++){
                mat[i][j]=diag[m];
                i++;
                j++;
            }
        }
        return mat;
    }
};