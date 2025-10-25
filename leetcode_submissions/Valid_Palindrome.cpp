class Solution {
public:
    bool isPalindrome(string s) {
    string result = "";

    for (char c : s) {
        if (isalpha(c)) {
            result += tolower(c);
        }
        else if (isalnum(c)) {
            result += c;
        }
    }
        if(result==""){
            return true;
        }
        int n = result.size();
        for(int i =0;i<=n/2;i++){
            if(result[i]!=result[n-1-i]){
                return false;
            }
    }
    return true;
    }
};