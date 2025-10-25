class Solution {
public:
    int maxele(vector<vector<int>>& mat, int mid , int n){
        int max = INT_MIN;
        int index = -1;
        for(int i = 0;i<n;i++){
            if(mat[i][mid]>max){
                max = mat[i][mid];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> ans;
        int m = mat[0].size();
        int l = 0;
        int h = m-1;
        while(l<=h){
            int mid = (l+h)/2;
            int index = maxele(mat,mid,n);
            int left = mid-1>=0 ? mat[index][mid-1] : -1;
            int right = mid+1<m ? mat[index][mid+1] : -1;
            if(mat[index][mid]>left && mat[index][mid]>right){
                ans = {index,mid};
                return ans;
            }
            else if (mat[index][mid]<left){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        ans = {-1,-1};
        return ans;
    }
};