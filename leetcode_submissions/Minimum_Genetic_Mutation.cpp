class Solution {
public:
    int dfs(string &curr, string &endGene, vector<char>& word, unordered_set<string>& st, unordered_set<string>& visited) {
        if(curr == endGene) return 0;
        
        int res = 1e9;
        visited.insert(curr);
        
        for(int i = 0; i < curr.size(); i++) {
            char old = curr[i];
            for(char c : word) {
                if(c == old) continue;
                curr[i] = c;
                if(st.count(curr) && !visited.count(curr)) {
                    res = min(res, 1 + dfs(curr, endGene, word, st, visited));
                }
            }
            curr[i] = old;
        }
        
        visited.erase(curr); 
        return res;
    }
    
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> word = {'A','C','G','T'};
        unordered_set<string> st(bank.begin(), bank.end());
        unordered_set<string> visited;
        
        int ans = dfs(startGene, endGene, word, st, visited);
        return ans >= 1e9 ? -1 : ans;
    }
};
