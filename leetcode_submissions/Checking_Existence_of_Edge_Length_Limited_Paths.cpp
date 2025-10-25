class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionn(int x, int y) {
        int xp = find(x);
        int yp = find(y);
        if (xp != yp)
            parent[yp] = xp;
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        vector<array<int, 4>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i) {
            sortedQueries.push_back({queries[i][0], queries[i][1], queries[i][2], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end(), [](const array<int, 4>& a, const array<int, 4>& b) {
            return a[2] < b[2]; // Sort by limit
        });

        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        vector<bool> result(queries.size());
        int edgeIndex = 0;

        for (const auto& q : sortedQueries) {
            int u = q[0], v = q[1], limit = q[2], originalIndex = q[3];

            while (edgeIndex < edgeList.size() && edgeList[edgeIndex][2] < limit) {
                unionn(edgeList[edgeIndex][0], edgeList[edgeIndex][1]);
                edgeIndex++;
            }

            result[originalIndex] = (find(u) == find(v));
        }

        return result;
    }
};
