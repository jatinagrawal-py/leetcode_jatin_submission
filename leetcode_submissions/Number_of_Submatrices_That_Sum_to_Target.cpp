class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        for(int i = 0;i<r;i++){
            int sum  =0;
            for(int j = 0;j<c;j++){
                sum+=matrix[i][j];
                matrix[i][j]  = sum;
            }
        }
        int res = 0;


        for(int colwise = 0 ;colwise<c ; colwise++){

            for(int j = colwise ; j<c ; j++){

                unordered_map<int,int>mpp;
                mpp[0]=1;
                int sum = 0;

                for(int row = 0;row<r;row++){
                    int col = colwise>0 ? matrix[row][colwise-1] : 0;
                    sum+= matrix[row][j] - col;

                    if(mpp.find(sum-target)!=mpp.end()){
                        res+=mpp[sum-target];
                    }

                    mpp[sum]++;
                }
            }
        }
        return res;
    }
};