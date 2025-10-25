class Solution {
public:
    bool canTransform(string start, string target) {
        int n = start.length();
        int i = 0;
        int j = 0;

        while(i < n || j < n) {
            while(i < n && start[i] == 'X') {
                i++;
            }

            while(j < n && target[j] == 'X') {
                j++;
            }

            if(i == n || j == n) {
                return i == n && j == n;
            }

            if(start[i] != target[j]) {
                return false;
            }

            if(start[i] == 'L' && i < j) {
                return false;
            }

            if(start[i] == 'R' && i > j) {
                return false;
            }

            i++;
            j++;
            
        }

        return true;
    }
};