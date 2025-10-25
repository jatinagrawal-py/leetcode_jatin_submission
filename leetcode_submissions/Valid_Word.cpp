class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)return false;

        int vow = 0;
        int con = 0;
        unordered_set<char>st;
        st.insert('a');
        st.insert('e');st.insert('i');st.insert('o');st.insert('u');st.insert('A');st.insert('E');st.insert('I');st.insert('O');st.insert('U');

        for(auto it:word){
            if(it =='@' || it=='$' || it=='#' )return false;
            if(isdigit(it))continue;
            else{
                if(st.find(it)!=st.end())vow++;
                else con++;
            }
        } 

        if(vow<1 || con<1)return false;
        return true;
    }
};