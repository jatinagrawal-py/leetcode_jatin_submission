class Solution {
public:
    int solve(int n){
        string hehe = to_string(n);
        int ans = 0;
        for(auto it:hehe){
            ans+=(it-'0');
        }

        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(solve(nums[i])==i){
                return i;
            }
        }

        return -1;
    }
};