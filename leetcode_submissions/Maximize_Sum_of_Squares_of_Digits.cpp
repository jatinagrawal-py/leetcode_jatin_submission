class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num==1 && sum>=10)return "";
        string ans = string(num,'0');
        for(int i = 0;i<num;i++){
            if(sum>9){
                ans[i] = '9';
                sum-=9;
            }
            else{
                ans[i]=sum+'0';
                return ans;
            }
        }

        return "";
    }
};