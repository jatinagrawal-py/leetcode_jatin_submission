class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        // n-1 - x +1 =  k
        unordered_set<int>st;
        vector<int>ans;
        for(int i = n-1; i>=0 && st.size()<=k;i--){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
                ans.push_back(nums[i]);
            }

            if(st.size()==k)break;
        }

        return ans;
    }
};