class Solution {
public:
    int t[501][501];
    int solve(string &s1, string &s2, int i, int j) {
        if(i == s1.size()) return s2.size() - j;
        if(j == s2.size()) return s1.size() - i;

        if(t[i][j]!=-1)return t[i][j];

        if(s1[i] == s2[j]) {
            return solve(s1, s2, i + 1, j + 1);
        }

        int insertOp = 1 + solve(s1, s2, i, j + 1);
        int deleteOp = 1 + solve(s1, s2, i + 1, j);
        int replaceOp = 1 + solve(s1, s2, i + 1, j + 1);

        return t[i][j]= min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        memset(t , -1 , sizeof(t));
        return solve(word1, word2, 0, 0);
    }
};
