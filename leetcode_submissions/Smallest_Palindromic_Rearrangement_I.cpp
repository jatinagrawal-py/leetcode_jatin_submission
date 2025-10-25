class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n==1){
            return s;
        }

        string x = "";

        if(n%2==0){
            for(int i =1;i<=n/2;i++){
                x+=s[i-1];
            }
            sort(x.begin(),x.end());
            string y = x;
            reverse(y.begin(),y.end());
            x = x  + y;
        }
        else{
            for(int i =1;i<=n/2;i++){
                x+=s[i-1];
            }
            sort(x.begin(),x.end());
            string y = x;
            reverse(y.begin(),y.end());
            x = x + s[(n/2)] + y;
        }

        return x;
    }
};