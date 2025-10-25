#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isprime(string s) {
        s.erase(0, min(s.find_first_not_of('0'), s.size() - 1));
        
        if (s.empty()) return false;

        long long hehe;
        hehe = stoll(s);

        if (hehe < 2) return false;
        if (hehe == 2 || hehe == 3) return true;
        if (hehe % 2 == 0 || hehe % 3 == 0) return false;

        for (long long i = 5; i * i <= hehe; i += 6) {
            if (hehe % i == 0 || hehe % (i + 2) == 0) return false;
        }

        return true;
    }

    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        unordered_set<long long> st;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n ; j++) {
                string hehe = s.substr(i, j - i + 1);
                if (isprime(hehe)) {
                    st.insert(stoll(hehe));
                }
            }
        }

        vector<long long> muhe(st.begin(), st.end());
        sort(muhe.begin(), muhe.end());

        long long sum = 0;
        if (muhe.size() < 3) {
            for (auto it : muhe) {
                sum += it;
            }
        } else {
            int m = muhe.size();
            sum += muhe[m - 1];
            sum += muhe[m - 2];
            sum += muhe[m - 3];
        }

        return sum;
    }
};
