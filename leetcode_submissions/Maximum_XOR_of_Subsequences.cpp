class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int>basis(32,0);
        for(auto it:nums){
            for(int b = 31;b>=0;b--){
                if(!(it & (1<<b)))continue;
                if(!basis[b]){
                    basis[b]=it;
                    break;
                }
                it^=basis[b];
            }
        }
        int ans = 0;
        for(int b = 31;b>=0;b--){
            if((ans^basis[b])>ans){
                ans ^=basis[b];
            }
        }
        return ans;
    }
};