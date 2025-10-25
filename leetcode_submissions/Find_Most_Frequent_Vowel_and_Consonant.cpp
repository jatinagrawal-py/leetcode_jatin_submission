class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>freq(26,0);
        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        int vow = 0;
        int con = 0;

        for(auto it:s){
            if(st.count(it)){
                freq[it-'a']++;
                vow = max(vow,freq[it-'a']);
            }
            else{
                freq[it-'a']++;
                con = max(con,freq[it-'a']);
            }
        }

        return con+vow;
    }
};