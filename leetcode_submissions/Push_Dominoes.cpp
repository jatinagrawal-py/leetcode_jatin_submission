class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();
        vector<int> left(n, -1), right(n, -1);
        string ans = "";

        // Fill right forces ('R')
        int time = -1;
        for (int i = 0; i < n; i++) {
            if (d[i] == 'R') {
                time = 0;
                right[i] = time;
            } else if (d[i] == 'L') {
                time = -1;
            } else if (time != -1) {
                time++;
                right[i] = time;
            }
        }

        // Fill left forces ('L')
        time = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (d[i] == 'L') {
                time = 0;
                left[i] = time;
            } else if (d[i] == 'R') {
                time = -1;
            } else if (time != -1) {
                time++;
                left[i] = time;
            }
        }

        // Build the result string
        for (int i = 0; i < n; i++) {
            if (left[i] == -1 && right[i] == -1) {
                ans += d[i];
            } else if (left[i] == -1) {
                ans += 'R';
            } else if (right[i] == -1) {
                ans += 'L';
            } else if (left[i] == right[i]) {
                ans += '.';
            } else if (left[i] < right[i]) {
                ans += 'L';
            } else {
                ans += 'R';
            }
        }

        return ans;
    }
};
