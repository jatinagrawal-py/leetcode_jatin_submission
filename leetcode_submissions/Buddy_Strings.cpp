class Solution {
public:

    bool freqcheck(string s){
        unordered_map<char,int> mp;

        for(auto it :s){
            mp[it]++;
            if(mp[it]>1)return true;
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())return false;

        if(s==goal && freqcheck(s))return true;


        int c = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]!=goal[i])c++;
        }
        if(c!=2)return false;

        int c1;
        for(int i = 0 ; i<s.size();i++){
            if(s[i]!=goal[i]){
                c1 = i;
                break;
            }
        }
        int c2;
        for(int i = c1+1 ; i<s.size();i++){
            if(s[i]!=goal[i]){
                c2 = i;
                break;
            }
        }
        
        swap(s[c1],s[c2]);
        if(s==goal)return true;

        return false;
    }
};