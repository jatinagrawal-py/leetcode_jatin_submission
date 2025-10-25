class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(begin(c), end(c));  
        int n = c.size();
        for (int i = 0; i < n; ++i) {
            int h = n - i;
            if (c[i] >= h) {
                return h;
            }
        }
        return 0;
    }
};
