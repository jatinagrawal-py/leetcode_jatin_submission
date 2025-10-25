class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
       vector<int>arr(2001,0);

        for(auto it:nums){
            arr[it+1000]++;
        }

        sort(arr.begin(),arr.end());

        for(int i = 0;i<2000;i++){
            if(arr[i]==arr[i+1] && arr[i]!=0)return false;
        }
       
       return true;
    }
};