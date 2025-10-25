class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        int countz = 0;
        for(auto it:nums){
            if(it==0)countz++;
            x^=it;
        }
        if(x!=0)return nums.size();

        if(x==0 && countz<nums.size())return nums.size()-1;

        return 0;
    }
};