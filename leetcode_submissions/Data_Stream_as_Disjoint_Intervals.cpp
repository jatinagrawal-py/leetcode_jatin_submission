class SummaryRanges {
public:
    unordered_set<int>st;
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int>hehe(st.begin(),st.end());
        vector<vector<int>>ans;
        sort(hehe.begin(),hehe.end());

        for(int i = 0;i<hehe.size();i++){
            int left = hehe[i];
            while(i<hehe.size()-1 && hehe[i]+1==hehe[i+1]){
                i++;
            }
            ans.push_back({left,hehe[i]});
        }

        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */