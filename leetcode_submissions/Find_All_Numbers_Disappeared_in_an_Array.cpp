class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int hash[100000+1] = {0};

        vector<int> ans;
        for(auto it : nums){
            hash[it]++;
        }
        for(int i = 1 ; i<n+1 ;i++){
            if(hash[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};