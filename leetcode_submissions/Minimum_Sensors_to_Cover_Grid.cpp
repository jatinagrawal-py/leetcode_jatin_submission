class Solution {
public:
    int minSensors(int n, int m, int k) {
        if(k==0)return n*m;
        int sqsize = 2*k + 1;
        int lowery = (n+sqsize-1)/sqsize;
        int righty = (m+sqsize-1)/sqsize;
        return lowery*righty;
    }
};