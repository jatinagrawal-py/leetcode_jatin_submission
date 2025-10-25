class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        long long pair = 0;
        
        int i = 0;
        int j = 0;
        int n = nums.size();

        unordered_map<int,int>mpp;


        while(j<n){
            pair+=mpp[nums[j]];
            mpp[nums[j]]++;

            while(pair>=k){
                ans+=(n-j);
                mpp[nums[i]]--;
                pair-=mpp[nums[i]];
                i++;
            }

            j++;
        }

        return ans;

    }
};