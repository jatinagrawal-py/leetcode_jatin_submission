class Solution {
public:
    int MOD = 1e9 + 7;
    int rev(int x){
        int a  = 0;

        while(x>0){
            a = a*10;
            int rem = x%10;
            x = x/10;
            a = a+rem;
        }

        return a;
    }
    int countNicePairs(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            int a = rev(nums[i]);
            nums[i]=nums[i] - a;
        }

        unordered_map<int,int>mpp;

        for(auto it:nums){
            mpp[it]++;
        }

        int res = 0;
        for(auto it:mpp){
            res = (res + (1LL * it.second * (it.second - 1) / 2) % MOD) % MOD;
        }

        return res;
    }
};