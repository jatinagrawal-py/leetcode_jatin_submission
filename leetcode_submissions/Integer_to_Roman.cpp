class Solution {
public:
    string intToRoman(int num) {
        int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string symbol[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans = "";
        int value = num;
        while(value!=0){
            int used;
            int index;
            for(int i =  0;i<13;i++){
                if(value>=val[i]){
                    used = val[i];
                    index = i;
                    break;
                }
            }
            int times = value/used;
            for(int i = 0;i<times;i++){
                ans += symbol[index];
                value -=val[index];
            }
            //value = value%(used*times);
        }

        return ans;
    }
};