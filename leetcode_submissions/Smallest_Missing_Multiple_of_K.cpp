class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st(nums.begin(),nums.end());
        int j = 1;
        for(auto it:st){
            if(it%k==0 && it==j*k){
                j++;
            }
            else if(it%k==0 && it!=j*k){
                return k*j;
            }
        }
        return k*j;
    }
};