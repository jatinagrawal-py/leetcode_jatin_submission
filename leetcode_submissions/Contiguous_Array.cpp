class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int res = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0)sum-=1;
            else sum+=1;

            if(mpp.find(sum)!=mpp.end()){
                res = max(res , (i-mpp[sum]));
            }
            else{
                mpp[sum]=i;
            }
        }

        return res==INT_MIN ? 0 : res;
    }
};