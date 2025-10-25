class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
      unordered_map<int,vector<int>>mpp;

      for(auto it:adjacentPairs){
        mpp[it[0]].push_back(it[1]);
        mpp[it[1]].push_back(it[0]);
      }

      int n = adjacentPairs.size()+1;

      vector<int>ans(n);
      int i = 0;
      for(auto it:mpp){
        if(it.second.size()==1){
            ans[i] = it.first;
            i=n-1;
        }
      }

      for(int i = 1;i<n-1;i++){
        if(mpp[ans[i-1]].size()==1){
            ans[i]=mpp[ans[i-1]][0];
        }
        else{
            int a = mpp[ans[i-1]][0];
            int b = mpp[ans[i-1]][1];
            if(ans[i-2]==a){
                ans[i]=b;
            }
            else{
                ans[i]=a;
            }
        }
      }

      return ans;

    }
};