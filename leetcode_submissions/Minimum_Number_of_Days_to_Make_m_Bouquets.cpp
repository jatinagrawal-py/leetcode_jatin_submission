class Solution {
public:
    bool possible(int mid , vector<int>& bloomDay, int m, int k){

        int count = 0;

        for(int i =0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid)count++;

            else if(bloomDay[i]>mid)count=0;

            if(count>=k){
                m--;
                count = 0;
            }
        }

        return m<=0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // 1 bouqet -> k flower
        int n = bloomDay.size();
        long long total = 1LL * m * k;
        if(n< total)return -1;
        int ans = -1;
        int low = 0;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid = low + (high-low)/2;

            if(possible(mid,bloomDay,m,k)){
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