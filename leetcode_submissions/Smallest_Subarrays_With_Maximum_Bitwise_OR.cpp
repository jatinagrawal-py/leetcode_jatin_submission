class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>setbit(32,-1);
        vector<int>res(n);

        for(int i = n-1;i>=0;i--){
            int idx = i;
            for(int j = 0;j<32;j++){
                if(!(nums[i]&(1<<j))){
                    if(setbit[j]!=-1){
                        idx = max(idx,setbit[j]);
                    }
                }
                else{
                    setbit[j] = i;
                }
            }
            res[i] = idx-i+1;
        }

        return res;
    }
};