class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>ans;
        unordered_set<int>st(friends.begin(),friends.end());
        for(auto it:order){
            if(st.count(it)){
                ans.push_back(it);
            }
        }

        return ans;
    }
};