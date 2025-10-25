class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(begin(s),end(s));
            return s;
        }
        
        string temp = s;
        for(int l = 1;l<=s.size()-1;l++){
            string newtemp = s.substr(l) + s.substr(0, l);
            temp = min(temp,newtemp);
        }

        return temp;

    }
};