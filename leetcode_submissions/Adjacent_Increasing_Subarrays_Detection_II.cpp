class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        if(nums.size()==2){
            return 1;
        }
        int prevlen = 0;
        int curlen = 1;
        int k = INT_MIN;

        for(int i = 1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                curlen++;
                k = max(k,curlen/2);
            }
            else{
                if(prevlen!=0){
                    int hehe = min(prevlen , curlen);
                    k = max(k,hehe);
                    prevlen = curlen;
                }
                else{
                    prevlen = curlen;
                }
                curlen = 1;
            }
        }
        int hehe = min(prevlen , curlen);
        k = max(k,hehe);
        return k;
    }
};