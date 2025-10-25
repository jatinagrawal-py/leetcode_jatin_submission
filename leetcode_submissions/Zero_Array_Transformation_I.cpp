class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>hehe(n,0);
        
        for(auto it:queries){
            int l = it[0];
            int r = it[1];
            hehe[l]+=1;
            if(r+1<n)hehe[r+1]-=1;
        }

        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=hehe[i];
            hehe[i] = sum;
        }

        for(int i = 0;i<n;i++){
            if(hehe[i]<nums[i]){
                return false;
            }
        }


        return true;
    }
};