class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        reverse(digits.begin(),digits.end());
        int n = digits.size();

        int hehe = digits[0]+1;

        digits[0] = hehe%10;
        carry = hehe/10;
        
        int i = 1;
        while(carry!=0 && i<n){
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            i++;
        }

        if(carry>0){
            digits.push_back(carry);
        }

        reverse(begin(digits),end(digits));


        return digits;
    }
};