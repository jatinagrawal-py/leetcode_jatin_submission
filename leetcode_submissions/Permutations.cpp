class Solution {
public:
    void solve(vector<int>& nums  , vector<vector<int>>&ans , vector<int>&temp , unordered_set<int>&st){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(auto it:nums){
            if(st.find(it)==st.end()){
                temp.push_back(it);
                st.insert(it);
                solve(nums,ans,temp,st);
                temp.pop_back();
                st.erase(it);
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        unordered_set<int>st;
        solve(nums,ans,temp,st);

        return ans;
    }
};