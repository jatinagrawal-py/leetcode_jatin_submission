class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0){
            return 0;
        }

        vector<int>f(31,0);
        int res = 0;
        int sign = 1;
        f[0]=1;
        for(int i = 1;i<31;i++){
            f[i]  = 2*f[i-1] + 1;
        }

        for(int i = 30 ;i>=0 ;i--){
            int ith_bit = (n>>i)&1;

            if(ith_bit==1){
                res+=(sign*f[i]);
                sign = -1*sign;
            }

            
        }

        return res;
    }
};