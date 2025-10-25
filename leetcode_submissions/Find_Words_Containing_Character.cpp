class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        for(int i = 0;i<words.size();i++){
            unordered_set<char>st(words[i].begin(),words[i].end());
            if(st.find(x)!=st.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};