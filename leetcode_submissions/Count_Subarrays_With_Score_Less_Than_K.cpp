class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {


        long long count = 0;
        int n = nums.size();
        int j = 0;
        int i = 0;
        long long sum  =0;
        while(j<n){
            sum += (long long)nums[j];
            
            while(i<=j && sum*(long long)(j-i+1)>=k){
                sum-=nums[i];
                i++;
            }

            count+= (j-i+1);
            j++;
        }

        return count;
    }
};