class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countzero = 0;
        int product = 1;
        
        for(auto it:nums){
            if(it==0)countzero++;
            else{
                product*=it;
            }
        }

        vector<int>ans;

        if(countzero>=2){
            for(int i = 0;i<nums.size();i++){
                ans.push_back(0);
            }

            return ans;
        }

        if(countzero==1){
            for(int i = 0;i<nums.size();i++){
                if(nums[i]==0){
                    ans.push_back(product);
                }
                else{
                    ans.push_back(0);
                }
            }

            return ans;
        }

        
        for(auto it:nums){
            ans.push_back((product/it));
        }

        return ans;

    }
};