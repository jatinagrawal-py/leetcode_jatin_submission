class Solution {
public:

    void findpsee(vector<int>& arr, vector<int>& psee) {
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void findnse(vector<int>& arr, vector<int>& nse) {
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        int sum = 0;
        vector<int> psee(n, -1);
        vector<int> nse(n, n);

        findpsee(arr, psee);
        findnse(arr, nse);

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            long long contribution = (left * right % mod) * arr[i] % mod;
            sum = (sum + contribution) % mod;
        }

        return sum;
    }
};
