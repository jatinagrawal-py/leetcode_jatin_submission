class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        // i+1 tak shift karna hai oo
        int n = shifts.size();
        vector<int>hehe(n,0);
        hehe[n-1] = shifts[n-1]%26;

        for(int i = n-2;i>=0;i--){
            hehe[i] = (hehe[i+1] + shifts[i])%26;
        }

        for(int i = 0;i<n;i++){
            int idx  = s[i] - 'a';
            idx = (idx + hehe[i])%26;
            s[i] = idx + 'a';
        }

        return s;
    }
};