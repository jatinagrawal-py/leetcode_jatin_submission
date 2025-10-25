class Solution {
public:
    set<vector<int>>ans;

    void solve(vector<int>& nums , vector<int>& temp , vector<int>& vis){
        if(temp.size()==nums.size()){
            ans.insert(temp);
            return;
        }


        for(int i = 0;i<nums.size();i++){
            if(vis[i]==0){
                vis[i]=1;
                temp.push_back(nums[i]);
                solve(nums,temp,vis);
                vis[i]=0;
                temp.pop_back();
            }
        }
        return;
    }

    

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<int>temp;
        int n = nums.size();
        vector<int>vis(n,0);

        solve(nums,temp,vis);
        vector<vector<int>>hehe;
        for(auto it:ans)hehe.push_back(it);
        return hehe;
    }
};