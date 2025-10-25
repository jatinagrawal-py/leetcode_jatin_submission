class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>>mpp;
        for(int i = 0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it:mpp){
            vector<string>temp;
            for(auto ahh:it.second){
                temp.push_back(strs[ahh]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};