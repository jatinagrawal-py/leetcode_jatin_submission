class Solution {
public:
    int ans = 1;
    int dfs(unordered_map<int,vector<int>>&mpp , vector<int>& parent, string &s , int i){
        int count  = 1;
        int maxi1 = 0;
        int maxi2 = 0;

        for(auto it:mpp[i]){
            if(it==parent[i])continue;
            int child_count= dfs(mpp,parent,s,it);
            if(s[i]!=s[it]){
                if (child_count > maxi1) {
                maxi2 = maxi1;
                maxi1 = child_count;
            } else if (child_count > maxi2) {
                maxi2 = child_count;
            }

            }
        }
        count+=maxi1;
        count+=maxi2;
        ans = max(ans,count);
        return 1+maxi1;
    }
    int longestPath(vector<int>& parent, string s) {

        unordered_map<int,vector<int>>mpp;
        for(int i = 0;i<parent.size();i++){
            int v = parent[i];
            if(v!=-1){
                mpp[v].push_back(i);
                mpp[i].push_back(v);
            }
        }

        dfs(mpp,parent,s,0);

        return ans;
    }
};