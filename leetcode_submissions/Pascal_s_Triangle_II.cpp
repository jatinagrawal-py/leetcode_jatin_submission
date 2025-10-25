class Solution {
public:
    vector<int> getRow(int row) {
        int col  = row+1;
        vector<int>ans(col,1);
        int j = 1;
        for(int i = 1;i<col-1;i++){
            ans[i] = ((long long)ans[i-1]*(row-j+1))/j;
            j++;
        }

        return ans;
        // rowcj
    }
};