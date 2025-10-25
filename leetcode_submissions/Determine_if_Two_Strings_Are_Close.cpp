class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n!=m)return false;

        unordered_set<char> st1;
        unordered_set<char> st2;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(int i = 0;i<n;i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
            st1.insert(word1[i]);
            st2.insert(word2[i]);
        }
        if(st1!=st2)return false;

        multiset<int> stt1;
        multiset<int> stt2;

        for(auto it: mp1){
            stt1.insert(it.second);
        }
         for(auto it: mp2){
            stt2.insert(it.second);
        }

        if(stt1!=stt2)return false;

        return true;



    }
};