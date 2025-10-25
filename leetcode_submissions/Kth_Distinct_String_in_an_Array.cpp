class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
         unordered_map<string, int> countMap;

        // Count the occurrences of each string
        for (const auto& str : arr) {
            countMap[str]++;
        }

        // Find the k-th distinct string
        int distinctCount = 0;
        for (const auto& str : arr) {
            if (countMap[str] == 1) {
                distinctCount++;
                if (distinctCount == k) {
                    return str;
                }
            }
        }

        // If k distinct strings are not found, return an empty string
        return "";
    }
};