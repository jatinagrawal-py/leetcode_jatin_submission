class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for(int i = 0;i<=31;i++){
            int zero = 0;
            int one = 0;
            int temp = 1<<i;
            for(auto it:nums){
                
                if((temp&it) == 0){
                    zero++;
                }
                else{
                    one++;
                }
            }
            if(one%3!=0){
                res = (temp|res);
            }
        }
        return res;
    }
};