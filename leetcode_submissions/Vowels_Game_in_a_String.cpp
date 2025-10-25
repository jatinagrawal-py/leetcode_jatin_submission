class Solution {
public:
    bool doesAliceWin(string s) {
        // last move alice ko karna hai 
        // alice odd
        // bob even
        int count = 0;
        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        for(auto it:s){
            if(st.count(it)){
                count++;
            }
        }

        if(count%2==1)return true;
        if(count==0)return false;
        return true;
    }
};