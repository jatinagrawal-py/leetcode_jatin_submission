class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int i = 0; //size hi rakhega 
        int j = 0;

        while(i<=nums.size()){
            if(i==nums.size()){
            i = nums.size();
            break;
            }

            if(nums[i]>=0){
                break;
            }
            i++;
        }

        while(j<=nums.size()){
            if(j==nums.size()){
                j=0;
                break;
            }
            if(nums[j]>0){
                j = nums.size()-j;
                break;
            }
            j++;
        }

        return max(j,i);
    }
};