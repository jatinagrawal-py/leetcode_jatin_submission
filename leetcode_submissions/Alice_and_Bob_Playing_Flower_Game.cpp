class Solution {
public:
    long long flowerGame(int n, int m) {
        int nodd = 0;
        int neven = 0;
        int modd = 0;
        int meven = 0;

        if(n%2==1){
            nodd = n/2 + 1;
            neven = n/2;
        }
        if(n%2==0){
            nodd = n/2 ;
            neven = n/2;
        }
        if(m%2==1){
            modd = m/2 + 1;
            meven = m/2;
        }
        if(m%2==0){
            modd = m/2 ;
            meven = m/2;
        }

        long long ans = 0;
        ans += ((long long)nodd*meven);
        ans+= ((long long)neven * modd);

        return ans;
    }
};