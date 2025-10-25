class Solution {
public:
    int find(int maxi , vector<int>& weights){
        int day = 1;
        int cur = 0;

        for(auto it:weights){
            
            cur+=it;

            if(cur>maxi){
                day++;
                cur = it;
            }
        }

        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(begin(weights),end(weights));
        int high =  accumulate(begin(weights),end(weights),0);
        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(find(mid,weights)<=days){
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