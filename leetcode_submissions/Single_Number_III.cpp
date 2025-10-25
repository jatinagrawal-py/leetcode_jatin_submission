class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long Xor = 0;
        for(auto it:nums)Xor^=it;

        int b1 = 0;
        int b2 = 0;
        long long rightmost = (Xor&(Xor-1))^Xor;

        for(auto it:nums){
            if(it&rightmost)b1^=it;
            else{
                b2^=it;
            }
        }

        return {b1,b2};
    }
};