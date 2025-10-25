class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int>rem(value,0);
        for(auto it:nums){
            rem[((it%value)+value)%value]++;
        }
        int mini = INT_MAX;
        int idx = -1;
        for(int i = 0;i<value;i++){
            if(mini>rem[i]){
                mini = rem[i];
                idx = i;
            }
        }
        return value*rem[idx]+idx;
    }
};