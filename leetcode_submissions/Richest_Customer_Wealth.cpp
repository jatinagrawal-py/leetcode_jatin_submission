class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
        int  m = acc.size();
        int n = acc[0].size();
        vector<int> arr(m);
        for(int i=0;i<m;i++){
            int sum =0;
            for(int j=0;j<n;j++){
                sum = sum + acc[i][j];
            }
            arr[i]=sum;
        }
        sort(arr.begin(),arr.end());
        return arr[m-1];
    }
};