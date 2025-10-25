
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> array(nums.size());
        
        // Convert all integers to strings
        for (int i = 0; i < nums.size(); i++) {
            array[i] = to_string(nums[i]);
        }

        // Sort using a custom comparator
        sort(array.begin(), array.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // If the largest number is "0", return "0" (handles the case with multiple zeroes)
        if (array[0] == "0") {
            return "0";
        }

        // Concatenate all strings to form the largest number
        string ans = "";
        for (string s : array) {
            ans += s;
        }

        return ans;
    }
};
