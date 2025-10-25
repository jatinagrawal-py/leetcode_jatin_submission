class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> loser;
        unordered_set<int> allPlayers;

        for (auto& match : matches) {
            loser[match[1]]++; // Count losses
            allPlayers.insert(match[0]);
            allPlayers.insert(match[1]);
        }

        vector<vector<int>> ans(2); // Fix: Initialize two empty vectors

        for (int player : allPlayers) {
            if (loser.find(player) == loser.end()) {
                ans[0].push_back(player); // Player has 0 losses
            } else if (loser[player] == 1) {
                ans[1].push_back(player); // Player has exactly 1 loss
            }
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};
