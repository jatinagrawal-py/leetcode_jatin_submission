class Solution {
public:
    int solve(vector<int>&arr){
        int ans = 0;
        int count = 1;

        for(auto it:arr){
            if(it==1){
                ans+=count;
                count++;
            }
            else{
                count = 1;
            }
        }

        return ans;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int res = 0;

        for(int startrow = 0;startrow<m;startrow++){
            vector<int>onedarray(n,1);
            for(int endrow = startrow ; endrow<m;endrow++){

                for(int i = 0;i<n;i++){
                    onedarray[i] = onedarray[i] & mat[endrow][i];
                }

                res+=solve(onedarray);
            }
        }

        return res;
    }
};