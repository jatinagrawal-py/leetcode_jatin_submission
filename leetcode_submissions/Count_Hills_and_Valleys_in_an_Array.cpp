class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;

        temp.push_back(nums[0]);
        
        for(int i = 1;i<n;i++){
            if(nums[i-1]!=nums[i])temp.push_back(nums[i]);
        }

        int count = 0;

        for(int i = 1;i<temp.size()-1;i++){
            if(temp[i-1]<temp[i] && temp[i+1]<temp[i])count++;
            else if(temp[i-1]>temp[i] && temp[i+1]>temp[i])count++;
        }

        return count;
    }
};