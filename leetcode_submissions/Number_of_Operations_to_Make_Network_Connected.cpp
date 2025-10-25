class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] != i) {
            parent[i] = find(parent[i], parent); // Path compression
        }
        return parent[i];
    }

    void unionn(int x, int y, vector<int>& parent) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);
        if (rootX != rootY) {
            parent[rootY] = rootX; // Attach y's root to x's root
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1; // Not enough cables to connect all nodes
        }

        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int components = n;
        for (auto& it : connections) {
            int u = it[0], v = it[1];

            if (find(u, parent) != find(v, parent)) {
                unionn(u, v, parent);
                components--;
            }
        }

        return components - 1;
    }
};
