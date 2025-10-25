class Solution {
public:
    typedef long long ll;
    int numTilings(int n) {
        // 1-> 1 
        // 2 -> 2
        // 3 -> 5
        vector<ll>hehe(1001,-1);
        const int mod = 1e9 + 7;
        hehe[1] = 1;
        hehe[2] = 2;
        hehe[3] = 5;

        for(int i = 4;i<=n;i++){
            hehe[i] = (2ll *hehe[i-1] + hehe[i-3])%mod;
        }

        return (int)hehe[n];
    }
};