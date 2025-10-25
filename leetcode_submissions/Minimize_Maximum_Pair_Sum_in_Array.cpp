class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // 2,3,3,5
        // 7,6 -> 7
        
        //2,3,4,4,5,6
        // 8,8,8 -> 8

        sort(nums.begin(),nums.end());
        vector<int>pair;
        int n = nums.size();

        for(int i = 0;i<n/2 ;i++){
            int sum = nums[i]+nums[n-1-i];
            pair.push_back(sum);
        }

        sort(pair.begin(),pair.end());

        return pair.back();
    }
};