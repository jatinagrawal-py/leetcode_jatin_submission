class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int>st;
        st.insert(0);
        int curheight = 0;
        vector<pair<int,int>>arr;
        for(auto it:buildings){
            arr.push_back({it[0],it[2]*-1});
            arr.push_back({it[1],it[2]});
        }
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(auto it:arr){
            if(it.second<0){
                int height = it.second*-1;
                st.insert(height);
                if(*st.rbegin()!=curheight){
                    curheight  = *st.rbegin();
                    ans.push_back({it.first,curheight});
                }
            }
            else{
                int height = it.second;
                st.erase(st.find(height));
                if(*st.rbegin()!=curheight){
                    curheight  = *st.rbegin();
                    ans.push_back({it.first,curheight});
                }
            }
        }
        return ans;
    }
};