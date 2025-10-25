class Solution {
public:
    int reverse(int x) {
    int reversed = 0;
    
    while (x != 0) {
        int digit = x % 10;  // Get the last digit
        x /= 10;             // Remove the last digit from x

        // Check for overflow before updating reversed
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) {
            return 0;  // Overflow for positive numbers
        }
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8)) {
            return 0;  // Overflow for negative numbers
        }

        reversed = reversed * 10 + digit;  // Update reversed with the new digit
    }
    
    return reversed;


    }
};