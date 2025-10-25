class Solution {
public:
    bool isValid(string input) {
        stack<char>st;

        for(auto it:input){
            if(it=='(' || it=='{' || it=='[' ){
                st.push(it);
            }
            else if(st.empty()){
                
                return false;
            }
            else{
                if(it==')' && st.top()=='('){
                    st.pop();
                }
                else if(it==']' && st.top()=='['){
                    st.pop();
                }
                else if(it=='}' && st.top()=='{'){
                    st.pop();
                }
                else {
                    
                    return false;
                }
            }
        }
        if(st.size()>0){
          
            return false;
        }

        return true;
    }
};