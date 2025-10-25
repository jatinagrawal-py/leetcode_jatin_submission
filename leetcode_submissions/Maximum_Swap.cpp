class Solution {
public:
    int maximumSwap(int num) {
        string hehe = to_string(num);
        vector<int> idx(hehe.size());
        char maxi = hehe.back();
        int id = hehe.size() - 1;

        for(int i = hehe.size() - 1; i >= 0; i--) {
            if(hehe[i] > maxi) {
                maxi = hehe[i];
                id = i;
            }
            idx[i] = id;
        }

        for(int i = 0; i < hehe.size(); i++) {
            if(hehe[idx[i]] > hehe[i]) {
                swap(hehe[i], hehe[idx[i]]);
                break;
            }
        }

        return stoi(hehe);
    }
};
