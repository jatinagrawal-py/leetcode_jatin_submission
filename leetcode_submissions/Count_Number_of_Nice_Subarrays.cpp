class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;

        int ans = 0;
        int count = 0;
        mpp[0]=1;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]%2==1)count++;

            int rem = count-k;

            if(mpp.find(rem)!=mpp.end()){
                ans+=mpp[rem];
            }

            mpp[count]++;
        }

        return ans;
    }
};