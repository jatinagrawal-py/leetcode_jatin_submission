class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (auto it : nums) {
            int cur = it;

            while (!ans.empty() && __gcd(cur, ans.back()) > 1) {
                cur = ((long long)cur * ans.back()) / __gcd(cur, ans.back());
                ans.pop_back();
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
