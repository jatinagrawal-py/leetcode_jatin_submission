class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0, temp = 0;

        // Extend circle for wrap-around
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        int totalSize = colors.size();

        // Compute alternating property for the first window
        for (int i = 1; i < k - 1; i++) {
            if (colors[i] != colors[i - 1] && colors[i] != colors[i + 1]) {
                temp++;
            }
        }

        // If the first window is valid
        if (temp == k - 2) count++;

        // Sliding window
        for (int i = 1; i <= totalSize - k; i++) {
            // Remove the outgoing element's effect
            if (colors[i] != colors[i - 1] && colors[i] != colors[i + 1]) {
                temp--;
            }

            // Add the incoming element's effect
            int end = i + k - 2;
            if (colors[end] != colors[end - 1] && colors[end] != colors[end + 1]) {
                temp++;
            }

            // Check if the current window satisfies the condition
            if (temp == k - 2) count++;
        }

        return count;
    }
};
