class NumArray {
public:
    vector<int>hehe;
    vector<int>prefix;
    NumArray(vector<int>& nums) {
        hehe = nums;
        int sum = 0;
        for(auto it:nums){
            sum+=it;
            prefix.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int hehe1 = left-1<0 ? 0 : prefix[left-1];
        return prefix[right] - hehe1;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */