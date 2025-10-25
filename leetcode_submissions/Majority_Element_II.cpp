class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        int min = (int)(nums.size()/3) + 1;
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]==min){
                ans.push_back(nums[i]);
            }
            if(ans.size()==2){
                break;
            }
        }
        return ans;
    }
};