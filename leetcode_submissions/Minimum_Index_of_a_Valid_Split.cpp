class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // 0-i i+1-n-1 
        
        unordered_map<int,int> mpp;

        for(auto it:nums){
            mpp[it]++;
        }
        
        int count = INT_MIN;
        int x ;
        for(auto it: mpp){
            if(it.second>count){
                count = it.second;
                x = it.first;
            }
        }

        int count1 = 0;
        int count2=count;
        int i = 0;
        while(i<nums.size()-1){
            if(nums[i]==x){
                count1++;
                count2--;
            }
            if(count1*2>i+1 && count2*2>nums.size()-i-1){
                return i;
            }
            i++;
        }

        return -1;

        
    }
};