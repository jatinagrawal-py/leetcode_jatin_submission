class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        unordered_set<string>st(d.begin(),d.end());
        int n = s.size();
        int i = 0;
        string hehe = "";
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            int j= i;
            bool flag = false;
            while(j<n && s[j]!=' '){
                string temp = s.substr(i,j-i);
                if(st.find(temp)!=st.end()){
                    flag = true;
                    break;
                }
                j++;
            }
            hehe += s.substr(i,j-i);
            hehe+=" ";
            if(flag){
                while(j<n && s[j]!=' '){
                    j++;
                }
            }
           i = j;
        }
        hehe = hehe.substr(0,hehe.size()-1);
        return hehe;
        
    }
};