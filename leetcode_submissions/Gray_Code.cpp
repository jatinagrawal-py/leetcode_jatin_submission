class Solution {
public:
    vector<int> solve(int n) {
        if (n == 0) return {0};
        if (n == 1) return {0, 1};

        vector<int> prev = solve(n - 1);
        vector<int> ans;

        for (auto x : prev) ans.push_back(x);

        // int add = 1 << (n - 1); 
        for (int i = prev.size() - 1; i >= 0; i--) {
            prev[i]|=(1<<(n-1));
            ans.push_back((prev[i]));
        }

        return ans;
    }

    vector<int> grayCode(int n) {
        return solve(n);
    }
};
