class Solution {
public:
    double myPow(double x, int n) {
        long long m = n;  
        double ans = 1;

        long long power = abs(m); 

        while (power > 0) {
            if (power % 2 == 1) {
                ans *= x;
                power--;
            } else {
                x *= x;
                power /= 2;
            }
        }

        return (m < 0) ? 1 / ans : ans;
    }
};
