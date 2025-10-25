class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans(0);
        unordered_map<string,int> ma;

        stringstream ss(s1);
        string cha;
        
        while(getline(ss,cha,' ')){
            ma[cha]++;
        }

        stringstream ss2(s2);
        string cha2;
        while(getline(ss2,cha2,' ')){
            ma[cha2]++;
        }
        
        for(auto it: ma){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};