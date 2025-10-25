class Solution {
public:
    int solve(int dif , vector<int>& nums){
        int hehe = 0;
        int n = nums.size();
        for(int i = 0;i<n-1;){
            if(nums[i+1]-nums[i]<=dif){
                hehe++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return hehe;
    }
    int minimizeMax(vector<int>& nums, int p) {
        // max difference from all the pair is minimized -> sare pair ka diff nikalo usmai se jo maximum aye woh minimum hona chiaye sab mai se 
        // 1 1 2 3 7 10  -> 0 , 1 . 1 . 4 . 3 -> 0 ,  1 , 1 , 3 , 4
        // 1 2 2 4

        sort(nums.begin(),nums.end());
        int n = nums.size();

        int l = 0;
        int r = nums[n-1]-nums[0];
        int ans ;

        while(l<=r){
            int mid = l + (r-l)/2;

            int pair = solve(mid,nums);

            if(pair>=p){
                r = mid-1;
                ans = mid;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};