class Solution {
public:
    string removeSubstring(string s, int k) {
        string st = "";
        for(char c:s){
            st.push_back(c);

            if(st.size()>=2*k){
                bool balanced = true;
                for(int i = st.size()-2*k ; i<st.size()-k ;i++){
                    if(st[i]!='('){balanced=false ; break;}
                }
                for(int i = st.size()-k ; i<st.size() && balanced ;i++){
                    if(st[i]!=')'){balanced=false ; break;}
                }
                if(balanced){
                    st.resize(st.size()-2*k);
                }
            }
        }
        return st;
    }
};