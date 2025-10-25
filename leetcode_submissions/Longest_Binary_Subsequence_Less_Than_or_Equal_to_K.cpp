class Solution {
public:
    int longestSubsequence(string s, int k) {
        int val = 0;
        int count = 0;
        int power = 0;
        for(int i  =s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                count++;
                power++;
            }
            else{
                if(val+pow(2,power)<=k){
                    count++;
                    val = val+pow(2,power);
                    power++;
                }
            }
        }


        return count;
    }
};