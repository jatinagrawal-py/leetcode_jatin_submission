class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // 00 -> 0
        // 11 -> 0
        // 01 -> 1
        // 10 -> 1

        // 010 ^ 001 ^ 011 ^ 100 ? = 001
        int ans = 0;

        for(int i = 0;i<32;i++){
            int one = 0;
            for(auto it:nums){
                if((it>>i)&1  == 1){
                    one++;
                }
            }
            int isset = (k>>i)&1;
            if(isset==1 && one%2==0)ans++;
            else if(isset==0 && one%2==1)ans++;
        }

        return ans;
    }
};