class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int number = 0;
        int res = 0;
        int sign = 1;

        for(auto it:s){
            if(isdigit(it)){
                number = number*10 + (it-'0');
            }
            else if(it=='-'){
                res+= (number*sign);
                number = 0;
                sign = -1;
            }
            else if(it=='+'){
                res+= (number*sign);
                number = 0;
                sign = 1;
            }
            else if(it==')'){
                res +=number*sign;
                number = 0;
                int sig = st.top();
                st.pop();
                int hehe = st.top();
                st.pop();
                res *= sig;
                res+=hehe;
            }
            else if(it=='('){
                st.push(res);
                st.push(sign);
                res = 0;
                number = 0;
                sign = 1; 
            }
        }
        res+=(number*sign);
        return res;
    }
};