class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n = arr.size();
        unordered_map<int,int>mpp;
        int res = 1;

        for(auto it:arr){
            if(mpp.find((it-d))!=mpp.end()){
                mpp[it] = mpp[it-d]+1;
                res = max(res,mpp[it]);
            }
            else{
                mpp[it]=1;
            }
        }
        return res;
    }
};