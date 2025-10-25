class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>hehe(n , 0);

        for(auto it:shifts){
            int l = it[0];
            int r = it[1];
            int hi = it[2];
            if(hi==0){
                hehe[l]-=1;
                if(r+1<n)hehe[r+1]+=1;
            }
            else{
                hehe[l]+=1;
                if(r+1<n)hehe[r+1]-=1;
            }
        }

        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=hehe[i];
            hehe[i] = sum;
        }

        for(int i = 0;i<n;i++){
            int idx = ((hehe[i] + s[i] - 'a')%26 + 26)%26;
            s[i] = 'a' + idx;
        }

        return s;
    }
};