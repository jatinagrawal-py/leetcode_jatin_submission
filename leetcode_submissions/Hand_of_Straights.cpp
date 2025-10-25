class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int n = hand.size();
        if (n % g != 0) return false;

        map<int, int> mpp;
        for (int card : hand) {
            mpp[card]++;
        }

        while (!mpp.empty()) {
            int start = mpp.begin()->first;

            for (int i = 0; i < g; i++) {
                int current = start + i;
                if (mpp.find(current) == mpp.end()) return false;
                mpp[current]--;
                if (mpp[current] == 0) {
                    mpp.erase(current);
                }
            }
        }

        return true;
    }
};
