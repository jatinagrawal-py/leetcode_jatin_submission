class Solution {
public:
    vector<int> ans;
    int val = 1e9;

    void brute(int n, int k, int last, vector<int>& curr, vector<int>& div) {
        if (k == 0) {
            if (curr.size() > 1) {
                int hehe = curr.back() - curr.front();
                if (val > hehe) {
                    ans = curr;
                    val = hehe;
                }
            }
            return;
        }

        if (k == 1) {
            if (last <= n) {
                curr.push_back(n);
                brute(1, k - 1, n, curr, div);
                curr.pop_back();
            }
            return;
        }

        int idx = lower_bound(begin(div), end(div), last) - div.begin();

        for (int i = idx; i < div.size(); i++) {
            int d = div[i];
            if (n % d == 0) {
                curr.push_back(d);
                brute(n / d, k - 1, d, curr, div);
                curr.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> div;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                div.push_back(i);
                if (n / i != i) {
                    div.push_back(n / i);
                }
            }
        }

        sort(div.begin(), div.end());

        vector<int> curr;
        brute(n, k, 0, curr, div);

        return ans;
    }
};
