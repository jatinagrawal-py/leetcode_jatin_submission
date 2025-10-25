class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // index 1 based hai yar
        vector<int>freq(n+1,0);
        unordered_set<int>st;


        for(int i = 0;i<friendships.size();i++){
            int u = friendships[i][0];
            int v = friendships[i][1];

            unordered_set<int>lang(languages[u-1].begin(),languages[u-1].end());
            bool isthere = false;
            for(auto it:languages[v-1]){
                if(lang.count(it)){
                    isthere = true;
                    break;
                }
            }
            if(!isthere){
                st.insert(u);
                st.insert(v);
            }
        }

        for(auto it:st){
            for(auto v:languages[it-1]){
                freq[v]++;
            }
        }

        int maxi = *max_element(freq.begin(),freq.end());

        if(st.size()<=maxi)return 0;

        return st.size()-maxi;
    }
};