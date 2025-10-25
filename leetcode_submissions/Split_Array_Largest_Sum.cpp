class Solution {
public:
    int find(int maxi , vector<int>&nums){
        int sum = 0;
        int count= 1;

        for(auto it:nums){
            sum+=it;
            if(sum>maxi){
                count++;
                sum=it;
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(begin(nums),end(nums));
        int high = accumulate(begin(nums),end(nums),0);
        int ans = -1;

        while(low<=high){
            int mid = low+ (high-low)/2;

            if(find(mid,nums)<=k){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};