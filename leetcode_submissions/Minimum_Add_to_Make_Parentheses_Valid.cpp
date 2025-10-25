class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int ans = 0;
        for(auto it:s){
            if(it=='(')count++;
            else count--;

            if(count<0){
                ans++;
                count = 0;
            }
        }

        return ans+count;
    }
};