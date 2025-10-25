class Solution {
public:
    int longestValidParentheses(string s) {
        int count = 0;
        int open = 0;
        int ans = 0;

        for(auto it:s){
            if(it=='('){
                open++;
                count++;
            }
            else{
                open--;
                count++;
                if(open<0){
                    open=0;
                    count=0;
                }
                else if(open==0){
                    ans = max(ans,count);
                }
            }
        }
        count = 0;
        int close = 0;
        for(int i = s.size()-1;i>=0;i--){
            if(s[i]==')'){
                close++;
                count++;
            }
            else{
                close--;
                count++;
                if(close<0){
                    close=0;
                    count=0;
                }
                else if(close==0){
                    ans = max(ans,count);
                }
            }
        }

        return ans;
    }
};