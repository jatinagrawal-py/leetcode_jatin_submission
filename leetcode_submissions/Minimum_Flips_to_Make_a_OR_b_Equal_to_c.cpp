class Solution {
public:
    int minFlips(int a, int b, int c) {
        

        int flip= 0;

        while(a!=0 || b!=0 || c!=0){
            int cbit = c&1;
            int bbit = b&1;
            int abit = a&1;

            if(cbit==1){
                if(bbit==0 && abit==0){
                    flip++;
                }
            }
            else{
                if(bbit==1){
                    flip++;
                }
                if(abit==1){
                    flip++;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }

        return flip;
        
    }
};