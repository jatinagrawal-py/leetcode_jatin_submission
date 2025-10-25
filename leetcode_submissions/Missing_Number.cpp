class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int XOR = 0;

        for(int i = 1;i<=n;i++){
            XOR^=i;
            XOR^=nums[i-1];
        }

        return XOR;
    }
};