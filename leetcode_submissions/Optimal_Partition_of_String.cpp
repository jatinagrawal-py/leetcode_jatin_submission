class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>st;

        int ans = 1;
        for(auto it:s){
            if(st.find(it)!=st.end()){
                ans++;
                st.clear();
                st.insert(it);
            }
            else{
                st.insert(it);
            }
        }

        return ans;
    }
};