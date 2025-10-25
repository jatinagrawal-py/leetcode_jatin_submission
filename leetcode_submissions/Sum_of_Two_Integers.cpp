class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int ans = 0;

        for (int i = 0; i <= 31; i++) {
            int abit = (a >> i) & 1;
            int bbit = (b >> i) & 1;

            int sum = abit ^ bbit ^ carry;

            if (sum) {
                ans |= (1 << i); 
            }

            if ((abit & bbit) || (abit & carry) || (bbit & carry)) {
                carry = 1;
            } else {
                carry = 0;
            }
        }

        return ans;
    }
};
