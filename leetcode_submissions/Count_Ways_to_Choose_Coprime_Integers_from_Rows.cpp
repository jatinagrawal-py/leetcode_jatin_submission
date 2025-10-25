class Solution {
public:
    int MOD = 1e9 + 7;
    int temp[151][151];
    bool seen[151][151];

    int solve(int idx, int g , vector<vector<int>>&mat , int n) {
        if (idx == n) return g == 1;
        if (seen[idx][g]) return temp[idx][g];
        seen[idx][g] = true;

        long long res = 0;
        for (int x : mat[idx]) {
            int ng = (g == 0 ? x : gcd(g, x));
            res += solve(idx + 1, ng , mat , n);
            if (res >= MOD) res -= MOD;
        }
        return temp[idx][g] = res;
    }

    int countCoprime(vector<vector<int>>& mat) {
        int n = mat.size();
        memset(seen, 0, sizeof(seen));
        return solve(0, 0,mat,n);
    }
};
