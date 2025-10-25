class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> anns(0);
        for(int i=0;i<n;i++){
            ans =0;
            for(int j = 0;j<n;j++){
                if(j!=i && nums[j]<nums[i]){
                    ans = ans +1;
                }
            }
            anns.push_back(ans);
        }
        return anns;
    }
};