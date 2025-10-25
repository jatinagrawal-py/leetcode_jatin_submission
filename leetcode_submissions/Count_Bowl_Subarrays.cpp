class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        stack<int>st;
        long long count = 0;

        for(int i = 0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                int hehe = st.top();
                st.pop();
                if(i-hehe+1>=3){
                    count++;
                }
            }
            if(!st.empty() && i-st.top()+1>=3)count++;

            st.push(i);
        }

        return count;
    }
};