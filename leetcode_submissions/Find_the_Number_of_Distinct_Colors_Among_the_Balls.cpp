class Solution {
public:
    vector<int> queryResults(int l, vector<vector<int>>& q) {
        int n = q.size();
        vector<int>ans;
        unordered_map<int,int>hehe;
        unordered_map<int,int>mpp;

        for(auto it:q){
            int x = it[0];
            int y = it[1];
            if(hehe.find(x)==hehe.end()){
                mpp[y]++;
                hehe[x] =y;
            }
            else{
                mpp[hehe[x]]--;
                if(mpp[hehe[x]]==0){
                    mpp.erase(hehe[x]);
                }
                hehe[x] = y;
                mpp[y]++;
            }
            ans.push_back(mpp.size());
        }

        return ans;
    }
};