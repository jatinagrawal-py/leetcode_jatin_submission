class Solution {
public:
    int find(int x, vector<int>& parent) {  // Pass by reference
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);  // Path compression
    }

    void unionn(int x, int y, vector<int>& parent) {  // Pass by reference
        int rootx = find(x, parent);
        int rooty = find(y, parent);
        if (rootx != rooty) {
            parent[rooty] = rootx;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Perform Union operations
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            if (find(u, parent) != find(v, parent)) {
                unionn(u, v, parent);
            }
        }

        // Count component sizes
        unordered_map<int, int> componentSize;
        for (int i = 0; i < n; i++) {
            int root = find(i, parent);
            componentSize[root]++;
        }

        vector<int> freq;
        for (auto it : componentSize) {
            freq.push_back(it.second);
        }

        // Calculate the number of unreachable pairs
        long long ans = 0;
        long long sum = n;

        for (int size : freq) {
            sum -= size;
            ans += size * sum;
        }

        return ans;
    }
};
