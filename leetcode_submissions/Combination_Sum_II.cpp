class Solution {
public:
    void solve(vector<vector<int>>&ans , vector<int>& candidates, int target , int i , vector<int>&hehe){
    
            if(target==0){
                ans.push_back(hehe);
                return;
            }

        for(int j = i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1])continue;
            if(candidates[j]>target)break;
            hehe.push_back(candidates[j]);
            solve(ans,candidates,target-candidates[j],j+1,hehe);
            hehe.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>hehe;

        solve(ans,candidates,target,0,hehe);

        
        return ans;
    }
};