class Solution {
public:
    char find(char x, vector<char>& parent) {
        if (parent[x - 'a'] == x) return x;
        return parent[x - 'a'] = find(parent[x - 'a'], parent);
    }

    void unionn(char x, char y, vector<char>& parent, vector<int>& rank) {
        char px = find(x, parent);
        char py = find(y, parent);
        if (px == py) return;

        if (rank[px-'a'] > rank[py-'a']) {
            parent[py-'a'] = px;
        } 
        else if (rank[py-'a'] > rank[px-'a']) {
            parent[px-'a'] = py;
        } 
        else {
            parent[py-'a'] = px;
            rank[px-'a']++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<char> parent(26);
        vector<int> rank(26, 1);  // Corrected initialization

        for (int i = 0; i < 26; i++) {
            parent[i] = char('a' + i);
        }

        // Process all '==' equations first
        for (auto it : equations) {
            if (it[1] == '=') {
                unionn(it[0], it[3], parent, rank);
            }
        }

        // Process all '!=' equations next
        for (auto it : equations) {
            if (it[1] == '!') {
                if (find(it[0], parent) == find(it[3], parent)) {
                    return false;  // Conflict detected
                }
            }
        }

        return true;
    }
};
