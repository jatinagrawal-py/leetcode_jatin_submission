class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        int count = 1;
        int ans = 0;

        for (int i = 1; i < tasks.size(); i++) {
            if (tasks[i] == tasks[i - 1]) {
                count++;
            } else {
                if (count == 1) return -1; 
                ans += (count + 2) / 3; 
                count = 1;
            }
        }

        if (count == 1) return -1;
        ans += (count + 2) / 3;

        return ans;
    }
};
