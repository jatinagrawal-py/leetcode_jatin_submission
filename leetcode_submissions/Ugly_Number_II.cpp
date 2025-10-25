class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 1, i3 = 1 , i4 = 1;
        vector<int>arr(n+1);
        arr[1]=1;

        for(int i = 2;i<=n;i++){
            int a = arr[i2]*2;
            int b = arr[i3]*3;
            int c = arr[i4]*5;

            int d = min({a,b,c});

            arr[i]=d;

            if(d==a){
                i2++;
            }

            if(d==b){
                i3++;
            }

            if(d==c){
                i4++;
            }                        
        }


        return arr[n];
    }
};