class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        while(target!=startValue){
            if(target<startValue){
                target++;
                count++;
            }
            else if(target%2==1){
                target++;
                count++;
            }
            else{
                target/=2;
                count++;
            }
        }

        return count;
    }
};