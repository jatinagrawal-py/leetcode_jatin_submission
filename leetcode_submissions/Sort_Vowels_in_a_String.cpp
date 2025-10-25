class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char>st;
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        string hehe = "";

        for(auto it:s){
            if(st.count(it)){
                hehe+=it;
            }
        }

        sort(hehe.begin(),hehe.end());

        int j = 0;
        int i = 0;

        while(j<s.size()){
            if(st.count(s[j])){
                s[j] = hehe[i];
                i++;
            }
            j++;
        }

        return s;
    }
};