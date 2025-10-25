class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        s = s+s;
        int i = 0;
        int j = 0;
        while(j<s.size()){
            if(j-i+1==goal.size()){
                if(s.substr(i,j-i+1)==goal)return true;
                else{
                    i++;
                }
            }
            j++;
        }

        return false;
    }
};