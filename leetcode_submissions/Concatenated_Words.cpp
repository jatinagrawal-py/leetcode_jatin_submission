class Solution {
public:
    unordered_map<string , bool> mp;
    bool isconcatenated( string word , unordered_set<string>& st ){
        if(mp.find(word)!=mp.end()){
            return mp[word];
        }
        int l = word.size();

        for(int i = 0;i<l;i++){
            string prefix = word.substr(0,i+1);
            string sufix = word.substr(i+1);

            if((st.find(prefix)!=st.end() && st.find(sufix)!=st.end()) || (st.find(prefix)!=st.end() && isconcatenated(sufix,st))){
                return mp[word] = true;
            }
        }
        return mp[word]= false;
    }    

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        mp.clear();
        unordered_set<string> st(words.begin() , words.end());
        vector<string> ans ;
        for(int i = 0;i<words.size();i++){
            if(isconcatenated(words[i],st)){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};