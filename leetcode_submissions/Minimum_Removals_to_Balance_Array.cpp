class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int count = 0;
        
        if(nums.size()==1)return count;

        // 1 2 6 9 (3)
        // 1 2 5 (2)
        
        // gap jyada usase uda do
        
        sort(nums.begin(),nums.end());
        // min*k >= max
        int i = 0;
        int j = 0;
        int maxlen = INT_MIN;

        while(j<nums.size()){
           while(i<=j && (long long)nums[i]*k<nums[j]){
               i++;
           }

            if((long long)nums[i]*k>=nums[j]){
                int len = j-i+1;
                maxlen = max(maxlen,len);
            }
            j++;
        }

        return nums.size()-maxlen;
    }
};