class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target>x+y)return false;

        int gxd ;

        while(x>0 && y>0){
            if(x>y){
                x = x%y;
            }
            else{
                y = y%x;
            }
        }

        if(x==0)gxd = y;
        else gxd = x;

        return target%gxd==0;

        
    }
};