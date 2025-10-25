class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // 1 2 3 5 6
        int ans = 0;
        sort(nums.begin(),nums.end());

        int i = 0;
        int j = 0;

        while(j<nums.size()){

            if(nums[j]-nums[i]>k){
                ans++;
                i = j;
                continue;
            }

            j++;
        }
        
        ans++;

        return ans;
    }
};