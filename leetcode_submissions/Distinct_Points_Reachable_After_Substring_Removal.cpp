class Solution {
public:
    int distinctPoints(string s, int k) {
        // u -> right
        // d -> left
        // l -> niche
        // r -> upar
        set<pair<int,int>>st;
        if(s.size()==k)return 1;
        int x = 0;
        int y = 0;
        for(auto it:s){
            if(it=='U'){
                y++;
            }
            if(it=='D'){
                y--;
            }
            if(it=='L'){
                x--;
            }
            if(it=='R'){
                x++;
            }
        }
        
        for(int i = 0;i<k;i++){
            if(s[i]=='U'){
                y--;
            }
            if(s[i]=='D'){
                y++;
            }
            if(s[i]=='L'){
                x++;
            }
            if(s[i]=='R'){
                x--;
            }
        }
        int count=1;
        st.insert({x,y});

        for(int i = k;i<s.size();i++){
            int j = i-k;
            if(s[j]=='U'){
                y--;
            }
            if(s[j]=='D'){
                y++;
            }
            if(s[j]=='L'){
                x++;
            }
            if(s[j]=='R'){
                x--;
            }
            if(s[i]=='U'){
                y++;
            }
            if(s[i]=='D'){
                y--;
            }
            if(s[i]=='L'){
                x--;
            }
            if(s[i]=='R'){
                x++;
            }
            if(st.count({x,y})==0)count++;

            st.insert({x,y});
        }

        return count;
    }
};