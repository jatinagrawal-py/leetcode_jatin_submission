class Solution {
public:
    vector<string>ans;
    void solve(int open , int close , string &temp , int n){
        if(temp.size()==2*n){
            ans.push_back(temp);
        }

        if(open<n){
            temp.push_back('(');
            solve(open+1,close,temp,n);
            temp.pop_back();
        }
        if(close<open){
            temp.push_back(')');
            solve(open,close+1,temp,n);
            temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        solve(0,0,temp,n);
        return ans;
    }
};