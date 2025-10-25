class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool>hehe(n,false);
        int count = 0;

        for(int i = 0;i<n;i++){
            if(nums[i]==key){
                hehe[i]=true;
                count = k;
            }
            else if(count>0){
                hehe[i]=true;
                count--;
            }
        }

        for(int i = n-1;i>=0;i--){
            if(nums[i]==key){
                hehe[i]=true;
                count = k;
            }
            else if(count>0){
                hehe[i]=true;
                count--;
            }
        }

        vector<int>ans;

        for(int i = 0;i<n;i++){
            if(hehe[i])ans.push_back(i);
        }


        return ans;
    }
};