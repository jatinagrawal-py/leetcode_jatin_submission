class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans =0;
        for(int num : hours){
            if(num>=target){
                ans = ans +1;
            }
        }
        return ans;
    }
};