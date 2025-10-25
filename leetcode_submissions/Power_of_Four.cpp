class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        if((n&(n-1))!=0)return false;

        for(int i = 0;i<32;i++){
            if((n&(1<<i)) && (i%2!=0))return false;
        }

        return true;
    }
};