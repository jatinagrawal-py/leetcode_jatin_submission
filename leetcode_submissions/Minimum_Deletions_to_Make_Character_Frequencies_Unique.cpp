class Solution {
public:
    int minDeletions(string s) {
        vector<int>hehe(26,0);

        for(auto it:s){
            hehe[it-'a']++;
        }

        unordered_set<int>st;
        int ans =0;

        for(int i = 0;i<26;i++){
            if(hehe[i]==0)continue;
            while(st.find(hehe[i])!=st.end()){
                ans++;
                hehe[i]--;
            }
            if(hehe[i]==0){
                continue;
            }
            st.insert(hehe[i]);
        }

        return ans;
    }
};