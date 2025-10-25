class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it:nums){
            st.insert(it);
        }

        int ans = 0;

        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int count = 1;
                int ele = it;
                while(st.find(ele+1)!=st.end()){
                    count++;
                    ele++;
                }
                ans = max(count,ans);
            }
        }

        return ans;
    }
};