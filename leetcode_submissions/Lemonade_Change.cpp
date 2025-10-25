class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        unordered_map<int, int> amt;
        amt[5] = 0;
        amt[10] = 0;

        if (bills[0] > 5) {
            return false;  // If the first bill is more than $5, we can't give change.
        }

        for (int i : bills) {
            if (i == 5) {
                amt[5]++;
            }
            else if (i == 10) {
                if (amt[5] == 0) {
                    return false;  // Can't give $5 change if we don't have any $5 bills.
                }
                amt[5]--;
                amt[10]++;
            }
            else if (i == 20) {
                if (amt[10] > 0 && amt[5] > 0) {
                    amt[10]--;
                    amt[5]--;
                }
                else if (amt[5] >= 3) {
                    amt[5] -= 3;
                }
                else {
                    return false;  // Can't give the correct change for $20.
                }
            }
        }
        return true;
    }
};
