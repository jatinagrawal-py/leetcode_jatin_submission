class Solution {
public:
    int numberOfArrays(vector<int>& dif, int lower, int upper) {

        int minval = 0;
        int maxval  =0;
        int cur = 0;

        for(auto it:dif){
            cur+=it;
            maxval = max(cur,maxval);
            minval = min(cur,minval);

            if((upper-maxval - lower +minval + 1)<0){
                return 0;
            }
        }

        return upper-maxval - lower + minval + 1;
    }
};