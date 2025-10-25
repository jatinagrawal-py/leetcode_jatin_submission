class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<=10)return {};
        unordered_map<string,int>mpp;
        int i = 0;
        int j = 0;
        string hehe = "";
        int n = s.size();
        while(j<n){
            hehe+=s[j];
            while((j-i+1) > 10){
                hehe.erase(0,1);
                i++;
            }
            if((j-i+1) == 10){
                mpp[hehe]++;
            }
            j++;
        }
        vector<string>ans;
        for(auto it:mpp){
            if(it.second>=2){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};