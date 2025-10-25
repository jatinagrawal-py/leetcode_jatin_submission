class Solution {
public:
    char find(char x ,  vector<char>&parent){
        if(parent[x-'a']==x) return x;

        return parent[x-'a'] = find(parent[x-'a'],parent);
    }
    
    void unionn(char x , char y , vector<char>&parent){
        char xp = parent[x-'a'];
        char yp = parent[y-'a'];

        if(xp>=yp){
            parent[xp-'a'] = yp;
        }
        else{
            parent[yp-'a'] = xp;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        vector<char> parent(26);

        for(char hehe = 'a' ; hehe<='z' ; hehe++){
            parent[hehe-'a'] = hehe;
        }

        for(int i = 0; i < n; i++){
            if(find(s1[i],parent)!=find(s2[i],parent)){
                unionn(s1[i],s2[i],parent);
            }
        }

        

        for(int i = 0;i<baseStr.size();i++){
            baseStr[i] = find(baseStr[i],parent);
        }

        return baseStr;
    }
};
