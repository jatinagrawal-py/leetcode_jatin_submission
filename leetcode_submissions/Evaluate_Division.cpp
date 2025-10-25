class Solution {
public:
    vector<double> ans;

    void dfs(unordered_map<string, vector<pair<string, double>>>& adj, string s, string d, double product, unordered_set<string>& vis, bool& found) {
        if (adj.find(s) == adj.end() || adj.find(d) == adj.end()) {
            return;
        }

        if (s == d) {
            ans.push_back(product);
            found = true;
            return;
        }

        vis.insert(s);

        for (auto it : adj[s]) {
            if (vis.find(it.first) == vis.end()) {
                dfs(adj, it.first, d, product * it.second, vis, found);
                if (found) return; // stop once found
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            adj[a].push_back({b, values[i]});
            adj[b].push_back({a, 1.0 / values[i]});
        }

        for (int i = 0; i < queries.size(); i++) {
            unordered_set<string> vis;
            bool found = false;
            dfs(adj, queries[i][0], queries[i][1], 1.0, vis, found);
            if (!found) ans.push_back(-1.0);
        }

        return ans;
    }
};
