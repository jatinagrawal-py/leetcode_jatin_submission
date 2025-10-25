class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> st; 
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                st.insert(i); 
            } else {
                int lake = rains[i];
                if (mpp.find(lake) != mpp.end()) {
                    int last = mpp[lake];
                    auto it = st.upper_bound(last);
                    if (it == st.end()) return {}; 
                    ans[*it] = lake;
                    st.erase(it);
                }
                ans[i] = -1;
                mpp[lake] = i;
            }
        }
        return ans;
    }
};
