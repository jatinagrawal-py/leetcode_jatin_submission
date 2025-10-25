class Solution {
public:
    string findCommonResponse(vector<vector<string>>& r) {
        unordered_map<string,int>mpp;
        vector<string>hehe;

        for(int i = 0;i<r.size();i++){
            unordered_set<string>st(r[i].begin(),r[i].end());
            for(auto it:st){
                mpp[it]++;
            }
        }

        int maxi = INT_MIN;
        
        for(auto it:mpp){
            maxi = max(maxi,it.second);
        }

        for(auto it:mpp){
            if(it.second==maxi){
                hehe.push_back(it.first);
            }
        }

        sort(hehe.begin(),hehe.end());

        return hehe[0];
    }
};