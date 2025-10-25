class Solution {
public:
    int minimizeXor(int num1, int num2) {
    // Count the number of 1s in num1 and num2
    int count1 = __builtin_popcount(num1);
    int count2 = __builtin_popcount(num2);

    // If the number of 1s in num1 is equal to num2, return num1
    if (count1 == count2) {
        return num1;
    }
    // If num1 has more 1s than num2, reduce the number of 1s in num1
    else if (count1 > count2) {
        int x = 0; // Initialize the result
        int setBits = 0; // Count of set bits in the result

        // Traverse the bits of num1 from the leftmost (highest bit) to the rightmost
        for (int i = 31; i >= 0; i--) {
            if (num1 & (1 << i)) { // Check if the i-th bit of num1 is set
                x |= (1 << i); // Set the corresponding bit in x
                setBits++;
                if (setBits == count2) { // Stop once the required number of set bits is reached
                    break;
                }
            }
        }
        return x;
    }
    // If num1 has fewer 1s than num2, add more 1s to num1
    else {
        int rem = count2 - count1; // Remaining 1s to be added
        int i = 0; // Start from the least significant bit

        // Add 1s to num1 until rem becomes 0
        while (rem > 0) {
            if (!(num1 & (1 << i))) { // If the i-th bit of num1 is not set
                num1 |= (1 << i); // Set the i-th bit
                rem--;
            }
            i++; // Move to the next bit
        }
        return num1;
    }
    return -1; // This line should never be reached
}
};
