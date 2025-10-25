class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> array;
        int j = n;
        for(int i =0;i<n;i++){
            array.push_back(nums[i]);
            array.push_back(nums[j]);
            j = j+1;
        }
        return array;
    }
};