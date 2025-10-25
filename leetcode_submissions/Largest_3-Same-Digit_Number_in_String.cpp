class Solution {
public:
    string largestGoodInteger(string num) {
        char ele = '/';
        for(int i = 2;i<num.size();i++){
            if(num[i-2]==num[i-1] && num[i-1]==num[i]){
                ele = max(ele , num[i]);
            }
        }


        string ans = "";
        ans +=ele;
        ans +=ele;
        ans +=ele;

        if(ans[0]=='/')return "";


        return ans;
        
    }
};