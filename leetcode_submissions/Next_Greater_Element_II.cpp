class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        for(int i = nums.size()-1;i>=0;i--){
            while(!st.empty()&& nums[i]>=st.top()){
                st.pop();
            }
            st.push(nums[i]);
        }
        vector<int>ans(nums.size(),-1);

        for(int i = nums.size()-1;i>=0;i--){
            while(!st.empty()&& nums[i]>=st.top()){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(nums[i]);
        }

        return ans;
        
    }
};