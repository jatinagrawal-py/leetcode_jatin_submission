class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while(i<n && nums[i]<0){
            i++;
        }

        int j = i-1;

        vector<int>ans;

        while(j>=0 && i<n){
            if((nums[i]*nums[i])<(nums[j]*nums[j])){
                ans.push_back((nums[i]*nums[i]));
                i++;
            }       
            else{
                ans.push_back((nums[j]*nums[j]));
                j--;
            }
        }

        while(j>=0){
            ans.push_back(nums[j]*nums[j]);
            j--;
        }
        while(i<n){
            ans.push_back(nums[i]*nums[i]);
            i++;
        }


        return ans;
    }
};