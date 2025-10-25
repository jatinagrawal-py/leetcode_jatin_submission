class Solution {
public:
    int find(vector<int>&num , int maxi , int ans , int i){
        if(i>=num.size()){
            if(ans==maxi)return 1;
            return 0;
        }

        int take = find(num,maxi,ans|num[i],i+1);
        int nottake = find(num,maxi,ans,i+1);


        return take + nottake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(auto it:nums)maxi|=it;

        return find(nums,maxi,0,0);
    }
};