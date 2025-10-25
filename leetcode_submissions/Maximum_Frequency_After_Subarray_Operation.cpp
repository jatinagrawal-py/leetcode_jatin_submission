class Solution {
public:
    int kadane(vector<int>& nums, int num , int k){
        int sum = 0;
        int maxi = 0;
        for(auto it:nums){
            if(it==k){
                sum+=-1;
                if(sum<0)sum=0;
            }
            else if(it==num){
                sum+=1;
                maxi = max(sum,maxi);
            }
        }

        return maxi;
    }
    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int , int>mpp;

        for(auto it:nums){
            mpp[it]++;
        }

        int maxi = 0;
        for(auto it:mpp){
            maxi = max(maxi , kadane(nums,it.first , k));
        }

        return maxi + mpp[k];

    }
};