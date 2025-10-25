class Solution {
public:
    
    const int mod = 1e9 + 7;

    long long modPow(long long base, long long exp, long long m) {
        long long result = 1;
        base %= m;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % m;
            base = (base * base) % m;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        // if n is even n/2 jitni places hongi
        // if n is odd -> odd wali places ayengi 
        // agar odd hai toh -> 4 
        // agar even hai toh ->5

        long long oddplaces = n/2;
        long long evenplaces = n - oddplaces;

        int ans = (modPow(4,oddplaces,mod)*modPow(5,evenplaces,mod))%mod;

        return ans;
    }
};