class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> badaans(nums2.size(), -1); // Initialize the next smaller element array
    stack<int> st;

    // Traverse nums2 from right to left to calculate the next smaller elements
    for (int i = nums2.size() - 1; i >= 0; i--) {
        // Pop elements from the stack that are greater than or equal to nums2[i]
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }
        // If the stack is not empty, the top element is the next smaller element
        if (!st.empty()) {
            badaans[i] = st.top();
        }
        // Push the current element onto the stack
        st.push(nums2[i]);
    }

    // Prepare the result array for nums1
    vector<int> ans(nums1.size());
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            // Match nums1 elements to their position in nums2 and get the next smaller element
            if (nums1[i] == nums2[j]) {
                ans[i] = badaans[j];
                break; // No need to continue checking once a match is found
            }
        }
    }

    return ans;
    }
};