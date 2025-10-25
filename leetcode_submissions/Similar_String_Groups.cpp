class Solution {
public:
    bool isSimilar(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) ++diff;
            if (diff > 2) return false;
        }
        return diff == 2 || diff == 0;
    }

    void dfs(int u, vector<string>& strs, vector<bool>& visited) {
        visited[u] = true;
        for (int v = 0; v < strs.size(); ++v) {
            if (!visited[v] && isSimilar(strs[u], strs[v])) {
                dfs(v, strs, visited);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<bool> visited(n, false);
        int groups = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, strs, visited);
                groups++;
            }
        }

        return groups;
    }
};
