class Solution {
public:
    bool isprime(int n){
    if (n <= 1) return false;  // 0 and 1 are not prime
    if (n == 2 || n == 3) return true;  // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false;  // Eliminate multiples of 2 and 3

    // Check divisibility from 5 to sqrt(n), skipping even numbers
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
    }

    vector<int> closestPrimes(int left, int right) {
        
        vector<int> pn ;
        vector<int>ans{-1,-1};

        for(int i = left;i<=right;i++){
            if(isprime(i))pn.push_back(i);
        }

        if(pn.size()<2)return ans;

        int mi = INT_MAX;
        int a , b;
        for(int i = 0;i<pn.size()-1;i++){
            if(pn[i+1]-pn[i]<mi){
                mi = pn[i+1]-pn[i];
                ans[0] = pn[i];
                ans[1] = pn[i+1];
            }
        }
        return ans;
    }

};