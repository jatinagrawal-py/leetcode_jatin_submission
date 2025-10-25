class Solution {
public:
    const long long mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<long long> hehe(26, 0);

        for (char it : s) {
            hehe[it - 'a']++;
        }

        while (t--) {
            vector<long long> fake(26, 0);
            for (int i = 0; i < 26; i++) {
                if (hehe[i] > 0) {
                    if (i == 25) { // 'z'
                        fake[0] = (fake[0] + hehe[i]) % mod;
                        fake[1] = (fake[1] + hehe[i]) % mod;
                    } else {
                        fake[i + 1] = (fake[i + 1] + hehe[i]) % mod;
                    }
                }
            }
            hehe = fake;
        }

        long long ans = 0;
        for (auto it : hehe) {
            ans = (ans + it) % mod;
        }

        return (int)ans;
    }
};
